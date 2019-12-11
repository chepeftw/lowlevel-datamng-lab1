#include<stdio.h>
#include<unistd.h>

int main() {
    int pipefds[2];
    int returnstatus;

    char writemessages[2][20] = {"Hi", "Hello"};
    char readmessage[20];

    returnstatus = pipe(pipefds);

    if (returnstatus == -1) {
        printf("Unable to create pipe\n");
        return 1;
    }

    /* sending Hi to pipe */
    printf("Writing to pipe - Message 1 is %s\n", writemessages[0]);
    write(pipefds[1], writemessages[0], sizeof(writemessages[0]));

    /* receiving Hi from pipe */
    read(pipefds[0], readmessage, sizeof(readmessage));
    printf("Reading from pipe – Message 1 is %s\n", readmessage);

    /* sending Hello to pipe */
    printf("Writing to pipe - Message 2 is %s\n", writemessages[0]);
    write(pipefds[1], writemessages[1], sizeof(writemessages[0]));

    /* receiving Hello from pipe */
    read(pipefds[0], readmessage, sizeof(readmessage));
    printf("Reading from pipe – Message 2 is %s\n", readmessage);

    return 0;
}