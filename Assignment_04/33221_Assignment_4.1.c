#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxItems 5   // Maximum items a producer can produce or a consumer can consume
#define BufferSize 5 // Size of the buffer

// counting sema
sem_t empty;
sem_t full;

int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex; //sema binary

void *producer(void *pno)
{
    int item;
    for (int i = 0; i < MaxItems; i++)
    {
        item = rand(); // Produce an random item
        sem_wait(&empty); // empty++
        pthread_mutex_lock(&mutex); // m=0

        // Critical section 
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno), buffer[in], in);
        in = (in + 1) % BufferSize;

        pthread_mutex_unlock(&mutex); //m=1
        sem_post(&full); //full++
    }
    return 0;
}


void *consumer(void *cno)
{
    for (int i = 0; i < MaxItems; i++)
    {
        sem_wait(&full); //--
        pthread_mutex_lock(&mutex); //0

        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n", *((int *)cno), item, out);
        out = (out + 1) % BufferSize;

        pthread_mutex_unlock(&mutex); //1
        sem_post(&empty); //++
    }
    return 0;
}

int main()
{

    pthread_t pro[5], con[5];

    pthread_mutex_init(&mutex, NULL); //sema init=1

    sem_init(&empty, 0, BufferSize);

    sem_init(&full, 0, 0);

    int a[5] = {1, 2, 3, 4, 5}; //Just used for numbering the producer and consumer

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&pro[i], NULL, producer, (void *)&a[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_create(&con[i], NULL, consumer, (void *)&a[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        pthread_join(pro[i], NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(con[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}