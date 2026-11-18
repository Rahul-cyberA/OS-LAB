#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    char message[100];
    mkfifo("myfifo", 0666);

    int fd = open("myfifo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    read(fd, message, sizeof(message));
    printf("Message received: %s\n", message);
    close(fd);
    unlink("myfifo");
    return 0;
}
