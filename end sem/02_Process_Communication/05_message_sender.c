#include <stdio.h>
#include <string.h>
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
    msg.type = 1;
    printf("Enter message: ");
    fgets(msg.text, sizeof(msg.text), stdin);

    if (msgsnd(id, &msg, sizeof(msg.text), 0) == -1) {
        perror("msgsnd");
        return 1;
    }
    printf("Message sent.\n");
    return 0;
}
