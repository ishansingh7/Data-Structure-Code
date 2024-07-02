#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack* next;
};

void push(struct stack** head, int value) {
    struct stack* newnode = (struct stack*)malloc(sizeof(struct stack));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = value;
    newnode->next = *head;
    *head = newnode;
}

void pop(struct stack** head) {
    if (*head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct stack* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Element popped from the stack\n");
}

void display(struct stack* head) {
    if (head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements in the stack are: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct stack* head = NULL;
    int choice, value;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&head, value);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
