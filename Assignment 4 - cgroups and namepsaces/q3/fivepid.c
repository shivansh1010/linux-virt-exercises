#define _GNU_SOURCE
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sched.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                        } while (0)

static int main_func(void *arg) {
    sleep(1);

    for (int i=0 ; i<5 ; i++) {
        pid_t main_pid = fork();
        if (main_pid == 0) {
            char *args[] = {"chroot","/home/sd/Desktop/q3/","./a.out", "cga4", NULL};
            // char *args[] = {"bash", "b.sh", NULL};
            execvp(args[0], args);
            perror("execvp failed");
        } 
        else {
            waitpid(main_pid, NULL, 0);
        }
    }
    // sleep(100);
    return 0;
}

#define STACK_SIZE (1024 * 1024)
static char child_stack[STACK_SIZE];

void echopid(char a[], int c) {
    FILE* outfile = fopen(a, "w");
    if (outfile != NULL) {
        fprintf(outfile, "%d", c);
        fclose(outfile);
    }
    else {
        printf("Unable to open file\n");
    }
}

int main(int argc, char *argv[]) {
    pid_t child_pid;
    child_pid = clone(main_func, 
                    child_stack + STACK_SIZE, 
                    CLONE_NEWPID | SIGCHLD, NULL);
    if (child_pid == -1)
        errExit("clone");
    printf("PID of main_proc created by clone() is %ld\n", (long) child_pid);

    echopid("/sys/fs/cgroup/cpu/cga4/cgroup.procs", child_pid);

    if (waitpid(child_pid, NULL, 0) == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
