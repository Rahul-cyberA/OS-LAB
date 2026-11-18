// Write student details to a file in the parent process, then read and print the file in the child process.

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;
    FILE *fp;
    char ch;

    pid = fork();

    if (pid > 0)
    {
        fp = fopen("input.txt", "w");

        fprintf(fp, "Name: Student\n");
        fprintf(fp, "University Roll No: 123456\n");
        fprintf(fp, "Class: B.Tech CSE\n");

        fclose(fp);

        wait(NULL);
    }
    else
    {
        fp = fopen("input.txt", "r");

        printf("Contents of input.txt:\n");

        while ((ch = fgetc(fp)) != EOF)
        {
            printf("%c", ch);
        }

        fclose(fp);
    }

    return 0;
}