#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    int processID = fork();

    // Parent Process
    if (processID)
    {
        printf("Parent Process Started (%i) \n", processID);
        sleep(1000);
        printf("Parent Process Ended \n");
    }

    // Child Process
    else
    {
        printf("Child Process Started (%i) \n", processID);
        printf("Child Process Ended \n");
    }

    return 0;
}