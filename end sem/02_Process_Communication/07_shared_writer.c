#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    key_t key = ftok(".", 'B');
    int id = shmget(key, 1024, 0666 | IPC_CREAT);
    if (id == -1) {
        perror("shmget");
        return 1;
    }

    char *data = (char *)shmat(id, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat");
        return 1;
    }

    printf("Enter a message: ");
    fgets(data, 1024, stdin);
    printf("Message stored in shared memory.\n");
    shmdt(data);
    return 0;
}
