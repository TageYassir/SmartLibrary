typedef struct QueueNode {
    char book[100]; // Allocate enough space for book titles
    struct QueueNode* next;
} QueueNode;
