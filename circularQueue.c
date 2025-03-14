#define MAX_RESERVATIONS 10

typedef struct CircularQueue{
    char books[MAX_RESERVATIONS][50];
    int front, rear, count;
} CircularQueue;