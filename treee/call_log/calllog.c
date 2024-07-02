#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a call log
struct CallLog {
    int callNumber;
    char callerName[50];
    int duration;
    struct CallLog* next;
};

// Structure to represent a queue of call logs
struct Queue {
    struct CallLog *front, *rear;
};

// Function to create a new call log
struct CallLog* createCallLog(int callNumber, char callerName[], int duration) {
    struct CallLog* newLog = (struct CallLog*)malloc(sizeof(struct CallLog));
    newLog->callNumber = callNumber;
    strcpy(newLog->callerName, callerName);
    newLog->duration = duration;
    newLog->next = NULL;
    return newLog;
}

// Function to create a new empty queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to add a call log to the end of the queue
void enqueue(struct Queue* queue, struct CallLog* log) {
    if (queue->rear == NULL) {
        queue->front = queue->rear = log;
        return;
    }
    queue->rear->next = log;
    queue->rear = log;
}

// Function to remove a call log from the front of the queue
struct CallLog* dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return NULL;
    struct CallLog* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    return temp;
}

// Function to display all call logs in the queue
void displayQueue(struct Queue* queue) {
    struct CallLog* current = queue->front;
    printf("Call Log:\n");
    while (current != NULL) {
        printf("Call Number: %d\n", current->callNumber);
        printf("Caller Name: %s\n", current->callerName);
        printf("Duration: %d minutes\n", current->duration);
        printf("\n");
        current = current->next;
    }
}

int main() {
    struct Queue* callLogQueue = createQueue();

    int callNumber, duration, choice;
    char callerName[50];

    do {
        printf("\n1. Add Call Log\n");
        printf("2. Display Call Logs\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Call Number: ");
                scanf("%d", &callNumber);
                printf("Enter Caller Name: ");
                scanf("%s", callerName);
                printf("Enter Call Duration (in minutes): ");
                scanf("%d", &duration);
                enqueue(callLogQueue, createCallLog(callNumber, callerName, duration));
                printf("Call Log added successfully.\n");
                break;
            case 2:
                displayQueue(callLogQueue);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while(choice != 3);

    // Free allocated memory before exiting
    struct CallLog *temp;
    while(callLogQueue->front != NULL) {
        temp = dequeue(callLogQueue);
        free(temp);
    }
    free(callLogQueue);

    return 0;
}