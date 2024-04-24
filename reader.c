#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, write_block;
int data = 0, readers_count = 0;

void *reader(void *arg) {
    int reader_id = *(int *)arg;
    sem_wait(&mutex);
    readers_count++;
    if (readers_count == 1) {
        sem_wait(&write_block);
    }
    sem_post(&mutex);
    
    printf("Reader %d read data: %d\n", reader_id, data);
    
    sem_wait(&mutex);
    readers_count--;
    if (readers_count == 0) {
        sem_post(&write_block);
    }
    sem_post(&mutex);
}

void *writer(void *arg) {
    int writer_id = *(int *)arg;
    sem_wait(&write_block);
    data++;
    printf("Writer %d wrote data: %d\n", writer_id, data);
    sem_post(&write_block);
}

int main() {
    pthread_t readers[5], writers[5];
    sem_init(&mutex, 0, 1);
    sem_init(&write_block, 0, 1);

    int reader_ids[5], writer_ids[5];
    for (int i = 0; i < 5; i++) {
        reader_ids[i] = i + 1;
        writer_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, (void *)&reader_ids[i]);
        pthread_create(&writers[i], NULL, writer, (void *)&writer_ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&write_block);
    
    return 0;
}