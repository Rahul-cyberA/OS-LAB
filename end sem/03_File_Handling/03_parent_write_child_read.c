#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    FILE *fp = fopen("student_data.txt", "w");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char name[50];
    int roll;
    printf("Enter name: ");
    scanf("%49s", name);
    printf("Enter roll number: ");
    scanf("%d", &roll);

    fprintf(fp, "%s %d\n", name, roll);
    fclose(fp);

    pid_t pid = fork();
    if (pid == 0) {
        char readName[50];
        int readRoll;
        fp = fopen("student_data.txt", "r");
        if (fp == NULL) {
            perror("fopen");
            return 1;
        }
        fscanf(fp, "%49s %d", readName, &readRoll);
        printf("Child read from file: %s %d\n", readName, readRoll);
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
