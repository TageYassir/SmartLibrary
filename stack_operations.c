# include "stackNode.c"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void push(StackNode** top, char* book);
char* pop(StackNode** top);
void displayStack(StackNode* top);

// Push book onto the stack
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

// Pop book from the stack
char* pop(StackNode** top) {
    if (*top == NULL) {
        return "No books to return!";
    }
    StackNode* temp = *top;
    *top = (*top)->next;
    char* book = temp->book;
    free(temp);
    return book;
}

// Display stack contents
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
