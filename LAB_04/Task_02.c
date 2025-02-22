#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define MaxCrops 5  
#define warehouseSize 5  

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'}; 
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'};
pthread_mutex_t mutex;

void *Farmer(void *far)
{
    int num = *(int *)far;
    while (1)
    {
        
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        
        warehouse[in] = crops[in];
        printf("Farmer %d: Insert crop %c at room %d\n", num, crops[in], in);

        in = (in + 1) % warehouseSize;

        
        printf("Warehouse: ");
        for (int i = 0; i < warehouseSize; i++)
        {
            printf("%c ", warehouse[i]);
        }
        printf("\n");

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        
        sleep(1);
    }
}

void *ShopOwner(void *sho)
{
    int num = *(int *)sho;
    while (1)
    {
        
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        
        printf("ShopOwner %d: Remove crop %c from room %d\n", num, warehouse[out], out);
        warehouse[out] = 'N'; 

        out = (out + 1) % warehouseSize;

        
        printf("Warehouse: ");
        for (int i = 0; i < warehouseSize; i++)
        {
            printf("%c ", warehouse[i]);
        }
        printf("\n");

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        
        sleep(1);
    }
}

int main() {
    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize); // when the warehouse is full thread will wait
    sem_init(&full, 0, 0); // when the warehouse is empty thread will wait

    int a[5] = {1, 2, 3, 4, 5}; // Just used for numbering the Farmer and ShopOwner

    // create 5 threads for Farmers and 5 threads for ShopOwners
    for (int i = 0; i < 5; i++) {
        pthread_create(&Far[i], NULL, Farmer, (void *)&a[i]);
        pthread_create(&Sho[i], NULL, ShopOwner, (void *)&a[i]);
    }

    // wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(Far[i], NULL);
        pthread_join(Sho[i], NULL);
    }

    // Closing or destroying mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}


