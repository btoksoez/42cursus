#include "../philo.h"

#define NUM_THREADS 1
#define NUM_ITERATIONS 10

// Shared variable and mutex
int sharedVariable = 0;
pthread_mutex_t mutex;

// Thread function to increment shared variable
void *philo(void *arg) {

    "time arg has taken a fork"
    pthread_mutex_lock(&mutex);
    Fork[1] = 1;
    begin_last_meal =  get_time();
    "time arg is eating"
    unlock fork;
    "time arg is sleeping"
    "time arg is thinking"
    if begin_last time > time_to_die
        "time arg died"

    // Unlock mutex after accessing sharedVariable
    pthread_mutex_unlock(&mutex);

    ◦ timestamp_in_ms X has taken a fork ◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died

    // Introduce a short delay
    usleep(100000); // 100ms
    (void)arg;
}
pthread_exit(NULL);
}

int main() {

    int num_threads = 
    pthread_t threads[num_threads];

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create thread
    pthread_create(&threads[0], NULL, threadFunction, NULL);

    // Main thread operation
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        // Lock mutex before accessing sharedVariable
        pthread_mutex_lock(&mutex);

        sharedVariable--;
        printf("Main: Decremented sharedVariable to %d\n", sharedVariable);

        // Unlock mutex after accessing sharedVariable
        pthread_mutex_unlock(&mutex);

        // Introduce a short delay
        usleep(200000); // 200ms
    }

    // Wait for thread to finish
    pthread_join(threads[0], NULL);

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}
