#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 2

int turn = 0;
int flag[NUM_THREADS];
sem_t mutex, sem[NUM_THREADS];

void* thread_function(void* id) {
    int tid = *(int*)id;

    for (int i = 0; i < 5; ++i) {
        // Entry section
        sem_wait(&mutex);
        turn = tid;
        flag[tid] = 1;
        sem_post(&mutex);

        // Wait until it's your turn
        sem_wait(&sem[tid]);
        
        // Critical section
        printf("Thread %d is in the critical section.\n", tid);

        // Exit section
        flag[tid] = 0;
        int other_tid = 1 - tid;
        turn = other_tid;

        // Signal the other thread to enter its critical section
        sem_post(&sem[other_tid]);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1};

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&sem[0], 0, 0);
    sem_init(&sem[1], 0, 0);

    // Create threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        int result = pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
        if (result) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&sem[0]);
    sem_destroy(&sem[1]);

    return 0;
}
