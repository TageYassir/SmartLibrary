#include "queueNode.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enqueue(QueueNode** front, QueueNode** rear, char* book);
char* dequeue(QueueNode** front, QueueNode** rear);
void displayQueue(QueueNode* front);

// Enqueue book
void enqueue(QueueNode** front, QueueNode** rear, char* book) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }

    strncpy(newNode->book, book, sizeof(newNode->book) - 1); // In this way we prevent from having overflow issue
    newNode->book[sizeof(newNode->book) - 1] = '\0'; // Make sure of the end of the arr book
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// Dequeue book
char* dequeue(QueueNode** front, QueueNode** rear) {
    // Check if the queue is empty
    if (*front == NULL) {
        return NULL;
    }

    QueueNode* temp = *front;

    char* book = (char*)malloc(strlen(temp->book) + 1);
    if (!book) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(book, temp->book);

    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);
    return book;
}

// Display
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