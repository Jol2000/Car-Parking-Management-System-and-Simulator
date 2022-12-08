#include <stdio.h>
#include <string.h>

#define MAX_CAPACITY 100
#define STORAGE_CAPACITY 7

typedef struct queue {
	// The current number of elements in the vector
	int size;

	// The content of the vector.
	char plateQueue[MAX_CAPACITY][STORAGE_CAPACITY];
} queue_t;

void plateInit(queue_t *queue);
void addPlate(queue_t *queue, char *plate);
void popPlate(queue_t* queue); 
void popRandom(queue_t* queue, int index); 
void printPlate(queue_t* queue);

// Initialise the queue
void plateInit(queue_t *queue){
    queue->size = 0;
    for (int i = 0; i < MAX_CAPACITY; i++){
        strcpy(queue->plateQueue[i], "empty");
    }
}

// Append plate to end of queue
void addPlate(queue_t* queue, char * plate){
    int old_size = queue->size;
    strcpy(queue->plateQueue[old_size], plate);
    queue->size = old_size + 1;
}

// Remove first plate from queue
void popPlate(queue_t* queue){
    int old_size = queue->size;
    char old_data[MAX_CAPACITY][STORAGE_CAPACITY];
    for (int i = 0; i < old_size; i++){
        strcpy(old_data[i], queue->plateQueue[i]);
    }
    for (int i = 0; i < old_size - 1; i++){
        strcpy(queue->plateQueue[i], old_data[i + 1]);
    }
    queue->size = old_size - 1;
}

// Pop a plate at an index
void popRandom(queue_t* queue, int index){
    int old_size = queue->size;
    char old_data[MAX_CAPACITY][STORAGE_CAPACITY];
    for (int i = 0; i < old_size; i++){
        strcpy(old_data[i], queue->plateQueue[i]);
    }
    for (int i = 0; i < index; i++){
        strcpy(queue->plateQueue[i], old_data[i]);
    }

    for (int i = index; i < old_size - 1; i++){
        strcpy(queue->plateQueue[i], old_data[i + 1]);
    }
    queue->size = old_size - 1;
}

// Print plates
void printPlate(queue_t* queue){
    printf("NUMBER OF PLATES: %d\n", queue->size); 
    for (int i = 0; i < queue->size; i++){
        printf("Plate number %d is: %s\n", i, queue->plateQueue[i]);
    }
}