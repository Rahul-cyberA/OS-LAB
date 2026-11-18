#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0) {
        FILE *fp = fopen("even.txt", "w");
        if (fp == NULL) {
            perror("fopen");
            return 1;
        }
        for (int i = 2; i <= 20; i += 2)
            fprintf(fp, "%d ", i);
        fclose(fp);
        printf("Child wrote even numbers to even.txt\n");
    }
    else if (pid > 0) {
        wait(NULL);
        FILE *fp = fopen("even.txt", "r");
        if (fp == NULL) {
            perror("fopen");
            return 1;
        }
        int num;
        printf("Numbers read by parent: ");
        while (fscanf(fp, "%d", &num) == 1)
            printf("%d ", num);
        printf("\n");
        fclose(fp);
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
