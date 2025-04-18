# include "priorityQueueNode.c"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void insertPriorityQueue(PriorityQueueNode** head, char* book, int priority);
void removePriorityQueue(PriorityQueueNode **head);
void displayPriorityQueue(PriorityQueueNode* head);

// Insert book into the priority queue
void insertPriorityQueue(PriorityQueueNode** head, char* book, int priority) {
    PriorityQueueNode* newNode = (PriorityQueueNode*)malloc(sizeof(PriorityQueueNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->book, book);
    newNode->priority = priority;
    newNode->next = NULL;

    if (*head == NULL || priority < (*head)->priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        PriorityQueueNode* temp = *head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Remove the highest priority book
void removePriorityQueue(PriorityQueueNode **head) {
    if (*head == NULL) {
        printf("No urgent requests to process!\n");
        return;
    }

    PriorityQueueNode* temp = *head;
    printf("Processed urgent request: %s\n",temp->book);
    *head = (*head)->next;

    free(temp);
}

// Display priority queue contents
void displayPriorityQueue(PriorityQueueNode* head) {
    if (head == NULL) {
        printf("No urgent book requests.\n");
        return;
    }
    printf("Urgent Book Requests (Priority Order):\n");
    PriorityQueueNode* temp = head;
    while (temp) {
        printf("- %s (Priority: %d)\n", temp->book, temp->priority);
        temp = temp->next;
    }
}
