#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void *funcThread(void *arg);
int main () {


    pthread_t Thread;
    pthread_create(&Thread, NULL, funcThread, NULL);
    pthread_join(Thread, NULL);


  return 0;
  }
 
 
void *funcThread(void *arg){
    int c = 1;
    for(int i=1;i<=5;i++){
        for (int j=1; j <=5; j++) {
            printf("Thread %d prints %d\n",i,c);
            c++;
            }
            }
            }
       






