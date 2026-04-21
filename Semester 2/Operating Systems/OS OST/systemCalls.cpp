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

        // Replace child with new program
        execl("/bin/ls", "ls", "-l", NULL);

        // Only runs if exec fails
        cout << "Exec failed\n";
    }

    else {
        // Parent process
        cout << "Parent waiting for child...\n";
        wait(NULL);
        cout << "Child finished\n";
    }

    return 0;
}