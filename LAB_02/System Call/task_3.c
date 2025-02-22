#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>




int main() {


   
    int a, b, c;
    //pid_t a,b,c;
    int count = 1;


    a = fork();
    if (a == 0) {
   
        if (getpid() % 2 != 0) {
            b = fork();
           
            if (b == 0) {
                count++;
            }
        }
        count++;
   
    } else {
        b = fork();
        if (b == 0) {
           
            if (getpid() % 2 != 0) {
                c = fork();
                if (c == 0) {
                   
                    count++;
                }
            }
            count++;
        }
         else {
            c = fork();
            if (c == 0) {
               
                if (getpid() % 2 != 0) {
                    count++;
                }
                count++;
            } else {
               
                count++;
            }
        }
    }


    printf("The total number of processes : %d\n",count);


    return 0;
}







