#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *funcThread(void *arg);
int main () {


    pthread_t Thread;
    pthread_create(&Thread, NULL, funcThread, NULL);
    pthread_join(Thread, NULL);


  return 0;
  }
 
 
void *funcThread(void *arg){
    for(int i=1;i<=5;i++){
        printf("thread-%d running\n",i);
        printf("thread-%d closed\n",i);
    }
    }
   

