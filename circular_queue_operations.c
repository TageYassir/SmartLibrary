# include <stdio.h>
# include <string.h>
# include "circularQueue.c"

void enqueueCircular(CircularQueue* cq, char* book);
char* dequeueCircular(CircularQueue* cq);
void displayCircularQueue(CircularQueue* cq);
void initCircularQueue(CircularQueue* cq);

// Initialize Circular Queue
void initCircularQueue(CircularQueue* cq) {
    cq->front = 0;
    cq->rear = -1;
    cq->count = 0;
}

// Enqueue book into Circular Queue (FIFO - Reservation)
void enqueueCircular(CircularQueue* cq, char* book) {
    if (cq->count == MAX_RESERVATIONS) {
        printf("Circular queue is full! Cannot reserve more books.\n");
        return;
    }

    cq->rear = (cq->rear + 1) % MAX_RESERVATIONS;
    strcpy(cq->books[cq->rear], book);
    cq->count++;
}

// Dequeue book from Circular Queue (FIFO - Processing reservation)
char* dequeueCircular(CircularQueue* cq) {
    if (cq->count == 0) {
        return "No reservations in queue!";
    }

    char* book = cq->books[cq->front];
    cq->front = (cq->front + 1) % MAX_RESERVATIONS;
    cq->count--;

    return book;
}

// Display Circular Queue Reservations
void displayCircularQueue(CircularQueue* cq) {
    if (cq->count == 0) {
        printf("No reservations in circular queue.\n");
        return;
    }

    printf("Reserved Books (Circular Queue Order):\n");
    for (int i = 0, idx = cq->front; i < cq->count; i++) {
        printf("- %s\n", cq->books[idx]);
        idx = (idx + 1) % MAX_RESERVATIONS;
    }
}
