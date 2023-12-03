#include <stdio.h>
#include <pthread.h>

// Function to compute the factorial of a number
void* factorialFunction(void* arg) {
    int n = *((int*)arg);
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    printf("Factorial of %d is %d\n", n, result);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int number = 5; // Compute factorial of 5

    // Create a new thread
    if (pthread_create(&thread, NULL, factorialFunction, &number) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Wait for the thread to finish
    if (pthread_join(thread, NULL) != 0) {
        perror("pthread_join");
        return 1;
    }

    printf("Thread has completed.\n");
    return 0;
}
