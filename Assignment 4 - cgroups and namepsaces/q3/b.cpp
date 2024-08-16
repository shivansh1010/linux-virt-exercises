// #include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <chrono>
#include <iostream>
#include <fstream>
using namespace std;

void func() {
    const long n = 2000000000;
    for (long i = 0; i < n; i++);
}

// void echopid(string a, string b, int c) {
//     ofstream outfile(a + b + "/cgroup.procs");
//     if (outfile.is_open()) {
//         outfile << c;
//         outfile.close();
//     }
//     else {
//         cout << "Unable to open file." << endl;
//     }
// }

int main(int argc, char* argv[]) {
    pid_t pid = getpid();
    // echopid("/sys/fs/cgroup/cpu/", argv[1], pid);

    auto start = chrono::high_resolution_clock::now();
    func();
    auto stop = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "PID " << pid << " took " << duration.count()/1000 << " | " << endl;
    return 0;
}