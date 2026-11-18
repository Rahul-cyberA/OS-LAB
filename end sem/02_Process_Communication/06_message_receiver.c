#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message {
    long type;
    char text[100];
};

int main()
{
    key_t key = ftok(".", 'A');
    int id = msgget(key, 0666 | IPC_CREAT);
    if (id == -1) {
        perror("msgget");
        return 1;
    }

    struct message msg;
    if (msgrcv(id, &msg, sizeof(msg.text), 1, 0) == -1) {
        perror("msgrcv");
        return 1;
    }
    printf("Received: %s", msg.text);
    msgctl(id, IPC_RMID, NULL);
    return 0;
}
