#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid == 0) {
        printf("I'm the child process!\n");
    } else if (pid > 0) {
        printf("I'm the parent process, and I created a child with PID %d\n", pid);
    } else {
        printf("Fork failed\n");
    }
    
    return 0;
}