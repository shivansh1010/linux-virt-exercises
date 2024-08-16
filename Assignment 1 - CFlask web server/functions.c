#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "civetweb.h"

static void home(char param_key[], char param_value[], char answer[]) {
    strcpy(answer, "Hello World!");
}

static void square(char param_key[], char param_value[], char answer[]) {
    if (strcmp("num", param_key)) {
        strcpy(answer, "1");
    } else {
        int num = atoi(param_value);
        sprintf(answer, "%d", num*num);
    }
}

static void cube(char param_key[], char param_value[], char answer[]) {
    if (strcmp("num", param_key)) {
        strcpy(answer, "1");
    } else {
        int num = atoi(param_value);
        sprintf(answer, "%d", num*num*num);
    }
}

static void helloworld(char param_key[], char param_value[], char answer[]) {
    if (strcmp("str", param_key)) {
        strcpy(answer, "Hello");
    } else {
        sprintf(answer, "Hello, %s", param_value);
    }
}

static void pingpong(char param_key[], char param_value[], char answer[]) {
    if (strcmp("str", param_key)) {
        strcpy(answer, "PingPong");
    } else {
        strcpy(answer, param_value);
    }
}

static void prime(char param_key[], char param_value[], char answer[]) {
    if (strcmp("num", param_key)) {
        strcpy(answer, "False");
    } else {
        int num = atoi(param_value);
        for (int i=2 ; i<=num/2 ; i++) {
            if (num%i == 0) {
                strcpy(answer, "False");
                return;
            }
        }
        strcpy(answer, "True");
    }
}

static void fibonacci(char param_key[], char param_value[], char answer[]) {
    if (strcmp("num", param_key)) {
        strcpy(answer, "1");
    } else {
        int num = atoi(param_value);
        if (num == 0) {
            strcpy(answer, "0");
        } else if (num == 1) {
            strcpy(answer, "1");
        } else {
            int a = 0, b = 1, c;
            for (int i=2 ; i<=num ; i++) {
                c = a+b;
                a = b;
                b = c;
            }
            sprintf(answer, "%d", c);
        }
    }
}
