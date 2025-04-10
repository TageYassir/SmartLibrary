#include "queueNode.c"  // Use a header file instead of "queueNode.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    strncpy(newNode->book, book, sizeof(newNode->book) - 1); // Prevent buffer overflow
    newNode->book[sizeof(newNode->book) - 1] = '\0'; // Ensure null termination
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
        return NULL; // Return NULL when queue is empty
    }

    QueueNode* temp = *front;

    // Allocate memory for the book string before freeing the node
    char* book = (char*)malloc(strlen(temp->book) + 1);
    if (!book) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(book, temp->book);

    // Update front and free the old front node
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);
    return book;  // Caller must free this memory after use
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