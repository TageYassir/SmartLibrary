typedef struct PriorityQueueNode {
    char book[50];
    int priority;
    struct PriorityQueueNode* next;
} PriorityQueueNode;