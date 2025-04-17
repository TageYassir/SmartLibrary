# include "stackNode.c"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void push(StackNode** top, char* book);

void pop(StackNode **top);
void displayStack(StackNode* top);

// Push book
void push(StackNode** top, char* book) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->book, book);
    newNode->next = *top;
    *top = newNode;
}

// Pop book
void pop(StackNode **top) {
    if (*top == NULL) {
        printf("No books to return!\n");
        return ;
    }
    StackNode* temp = *top;
    printf("Book returned is : %s\n", temp->book);
    *top = (*top)->next;
    free(temp);
}

// Display
void displayStack(StackNode* top) {
    if (top == NULL) {
        printf("No borrowed books.\n");
        return;
    }
    printf("Borrowed Books (LIFO Order):\n");
    StackNode* temp = top;
    while (temp) {
        printf("- %s\n", temp->book);
        temp = temp->next;
    }
}
