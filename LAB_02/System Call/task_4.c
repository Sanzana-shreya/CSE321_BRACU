#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




int main(int argc, char *argv[]) {
    pid_t pid;
    int status;


    pid = fork();


    if (pid == 0) {
        execl("./sort", "./sort", argv[1], argv[2], argv[3], argv[4], NULL);
    } else {
        waitpid(pid, &status, 0);


        execl("./oddeven", "./oddeven", argv[1], argv[2], argv[3], argv[4], NULL);
    }


    return 0;
}






