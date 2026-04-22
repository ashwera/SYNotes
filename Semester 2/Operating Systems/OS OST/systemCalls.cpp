#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    pid_t pid = fork();

    if(pid < 0) {
        cout << "Fork failed\n";
        return 1;
    }

    else if(pid == 0) {
        // Child process
        cout << "Child process (PID: " << getpid() << ")\n";
        cout << "Parent PID: " << getppid() << endl;
    }

    else {
        // Parent process
        cout << "Parent waiting for child...\n";
        wait(NULL);
        cout << "Child finished\n";
        cout << "Child process (PID: " << pid << ")\n";
        cout << "Parent PID: " << getpid() << endl;
    }

    return 0;
}