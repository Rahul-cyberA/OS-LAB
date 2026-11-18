#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int isPrime(int n)
{
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int main()
{
    int n, a[100], sum = 0, fd[2];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Invalid size\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
        sum += a[i];
    }

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }
    pid_t pid = fork();
    if (pid == 0) {
        close(fd[1]);
        read(fd[0], &sum, sizeof(sum));
        close(fd[0]);
        if (isPrime(sum)) printf("Child: %d is prime\n", sum);
        else printf("Child: %d is not prime\n", sum);
    }
    else if (pid > 0) {
        close(fd[0]);
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
        wait(NULL);
    }
    else {
        perror("fork");
        return 1;
    }
    return 0;
}
