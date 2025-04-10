# include <stdio.h>
# include "circular_queue_operations.c"
# include "stack_operations.c"
# include "queue_operations.c"
# include "priority_queue_operations.c"



void menu() {
    StackNode* borrowedBooks = NULL;
    QueueNode *reservationFront = NULL, *reservationRear = NULL;
    PriorityQueueNode* urgentRequests = NULL;
    CircularQueue reservationQueue;
    initCircularQueue(&reservationQueue);

    int choice;
    char book[50];
    int priority;

    do {
        printf("\nSmart Library Management System\n");
        printf("1. Borrow a book (LIFO)\n");
        printf("2. Return a book (LIFO)\n");
        printf("3. Reserve a book (FIFO)\n");
        printf("4. Process a reservation (FIFO)\n");
        printf("5. Urgent book request (Priority Queue)\n");
        printf("6. Process urgent request\n");
        printf("7. Circular queue reservation\n");
        printf("8. Process circular queue reservation\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                printf("Enter book to borrow: ");
                fgets(book,sizeof(book),stdin);
                push(&borrowedBooks, book);
                break;
            case 2:
                pop(&borrowedBooks);
                break;
            case 3:
                printf("Enter book to reserve: ");
                fgets(book,sizeof(book),stdin);
                enqueue(&reservationFront, &reservationRear, book);
                break;
            case 4:
                printf("Processed reservation: %s\n", dequeue(&reservationFront, &reservationRear));
                break;
            case 5:
                printf("Enter book for urgent request: ");
                fgets(book,sizeof(book),stdin);
                printf("Enter priority (lower is higher priority): ");
                scanf("%d", &priority);
                insertPriorityQueue(&urgentRequests, book, priority);
                break;
            case 6:
                removePriorityQueue(&urgentRequests);
                break;
            case 7:
                printf("Enter book for circular reservation: ");
                fgets(book,sizeof(book),stdin);
                enqueueCircular(&reservationQueue, book);
                break;
            case 8:
                printf("Processed circular reservation: %s\n", dequeueCircular(&reservationQueue));
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 9);
}
