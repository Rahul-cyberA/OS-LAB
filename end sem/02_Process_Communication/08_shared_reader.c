#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    key_t key = ftok(".", 'B');
    int id = shmget(key, 1024, 0666);
    if (id == -1) {
        perror("shmget");
        return 1;
    }

    char *data = (char *)shmat(id, NULL, 0);
    if (data == (char *)-1) {
        perror("shmat");
        return 1;
    }

    printf("Message from shared memory: %s", data);
    shmdt(data);
    shmctl(id, IPC_RMID, NULL);
    return 0;
}
