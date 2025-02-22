#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>




int main () {


    int par_id = 0;
    printf("1. Parent process ID: %d\n",par_id);
   
   
        pid_t child_pid = fork();
        if (child_pid == 0) {
        printf("2. Child process ID: %d\n", getpid());


       
        pid_t grandchild_pid1 = fork();
        if (grandchild_pid1 == 0) {
            printf("3. Grand Child process ID: %d\n", getpid());
            return 0;
        }


       
        pid_t grandchild_pid2 = fork();
        if (grandchild_pid2 == 0) {
            printf("4. Grand Child process ID: %d\n", getpid());
            return 0;
        }




        pid_t grandchild_pid3 = fork();
        if (grandchild_pid3 == 0) {
            wait(NULL);
            printf("5. Grand Child process ID: %d\n", getpid());
            return 0;
        }


    wait(NULL);
    wait(NULL);
    wait(NULL);
        return 0;
    }


    wait(NULL);
    return 0;
}






  

