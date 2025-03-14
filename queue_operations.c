# include "queueNode.c"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void enqueue(QueueNode** front, QueueNode** rear, char* book);
char* dequeue(QueueNode** front, QueueNode** rear);
void displayQueue(QueueNode* front);



// Enqueue book into the queue
void enqueue(QueueNode** front, QueueNode** rear, char* book) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->book, book);
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Dequeue book from the queue
char* dequeue(QueueNode** front, QueueNode** rear) {
    if (*front == NULL) {
        return "No reservations to process!";
    }

    QueueNode* temp = *front;
    char* book = temp->book;
    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);
    return book;
}

// Display queue contents
void displayQueue(QueueNode* front) {
    if (front == NULL) {
        printf("No book reservations.\n");
        return;
    }
    printf("Reserved Books (FIFO Order):\n");
    QueueNode* temp = front;
    while (temp) {
        printf("- %s\n", temp->book);
        temp = temp->next;
    }
}
