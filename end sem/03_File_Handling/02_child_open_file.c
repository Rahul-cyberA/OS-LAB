#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    FILE *fp = fopen("sample.txt", "w");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    fprintf(fp, "This file is opened by the child process.\n");
    fclose(fp);

    pid_t pid = fork();
    if (pid == 0) {
        fp = fopen("sample.txt", "r");
        if (fp == NULL) {
            perror("fopen");
            return 1;
        }
        char line[100];
        while (fgets(line, sizeof(line), fp) != NULL)
            printf("Child read: %s", line);
        fclose(fp);
    }
    else if (pid > 0) {
        wait(NULL);
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
