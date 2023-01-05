#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    // Fork returns the process ID in the parent process
    int pid = fork();

    if (pid < 0)
    {
        // exit(1)
        printf("Failed to fork. \n");
        return -1;
    }

    // Parent process
    if (pid > 0)
    {
        printf("Parent pid: %d \n", getpid());
    }

    // Child process
    else
    {
        printf("Child pid: %d \n", getpid());
    }

    return 0;
}