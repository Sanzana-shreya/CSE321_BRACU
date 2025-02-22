#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>






void compare(int *results) {
    if (results[0] == results[1] && results[1] == results[2]) {
        printf("Youreka.\n");
    } else if (results[0] == results[1] || results[1] == results[2] || results[0] == results[2]) {
        printf("Miracle.\n");
    } else {
        printf("Hasta la vista.\n");
    }
}


int ascii_sum(char *str) {
    int sum = 0;
    for (int i = 0; i < strlen(str); i++) {
        sum += (int) str[i];
    }
    return sum;
}


void *thread_func(void *arg) {
    char *username = (char *) arg;
    int sum = ascii_sum(username);
    int *result = malloc(sizeof(int));
    *result = sum;
    return (void *)result;
}


int main() {
    int THREADS = 4;
    pthread_t threads[THREADS];
    char *usernames[3] = {"sanzana", "mahrukh", "shreya"};
    int results[3];


    for (int i = 0; i <= 2; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) usernames[i]);
    }


    for (int i = 0; i <= 2; i++) {
        int *result;
        pthread_join(threads[i], (void **) &result);
        results[i] = *result;
        free(result);
    }


    pthread_create(&threads[3], NULL, (void *) compare, (void *) results);
    pthread_join(threads[3], NULL);


    return 0;
}

