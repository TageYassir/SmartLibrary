cmake_minimum_required(VERSION 3.30)
project(SmartLibrary C)

set(CMAKE_C_STANDARD 11)

add_executable(SmartLibrary main.c
        stackNode.c
        queueNode.c
        priorityQueueNode.c
        circularQueue.c
        stack_operations.c
        queue_operations.c
        priority_queue_operations.c
        circular_queue_operations.c
        menu.c
        testmain.c
)
