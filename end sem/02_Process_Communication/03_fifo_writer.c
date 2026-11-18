#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char message[100];
    mkfifo("myfifo", 0666);

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    int fd = open("myfifo", O_WRONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    write(fd, message, strlen(message) + 1);
    close(fd);
    return 0;
}
