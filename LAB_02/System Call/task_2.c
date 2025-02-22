#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>






void main () {


    int pid1, pid2, status;


    pid1 = fork();




    if (pid1 == 0) {
       
        pid2 = fork();
       
        if (pid2 == 0) {
            printf("I am grandchild.\n");
            }
        else {
            wait(&status);
            printf("I am child.\n");
            }
            }
    else {
   
        wait(&status);
        printf("I am parent.\n");
    }


   
}

