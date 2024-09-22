#include <stdio.h>
#include <unistd.h> // fork, getpid
#include <sys/wait.h> // Wait function

int main() {
    
    // Fork a child process
    pid_t pid = fork();

    // Fork failed
    if (pid < 0) {
        printf("Fork failed");
        return 1;
    }
    // Child process
    else if (pid == 0) {
        printf("Child Process: %d\n", getpid());
    }
    
    // Parent Process
    else {
        printf("Parent Process: %d\n", getpid());

        // wait for the child process to terminate
        sleep(30);
        printf("Parent Process: Child process ended\n");
    }

    return 0;
}