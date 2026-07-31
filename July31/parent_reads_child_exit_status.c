//Child exits with status 10 and parent reads it using wait()
// This program demonstrates how a child process can exit with a specific status code, and how the parent process can retrieve that status using the wait() system call.
    
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int status;
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child exiting with status 10\n");
        exit(10);
    }
    else
    {
        wait(&status);

        if (WIFEXITED(status))
        {
            printf("Parent received exit status = %d\n",
                   WEXITSTATUS(status));
        }
    }

    return 0;
}