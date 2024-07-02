#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Node creation
void node_create(struct node **head, int d) {
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    if (nn == NULL) {
        printf("Memory allocation is failed.\n");
        return;
    }
    nn->data = d;
    nn->next = *head;
    *head = nn;
}

// Insertion at the beginning
void insertat_beg(struct node **head, int d) {
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    if (nn == NULL) {
        printf("Memory allocation is failed.\n");
        return;
    }
    nn->data = d;
    struct node *temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = nn;
    nn->next = *head;
    *head = nn;
}

// Displaying circular linked list
void display(struct node *head) {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    struct node *head = NULL;

    insertat_beg(&head, 24);
    insertat_beg(&head, 28); 
    display(head);

    return 0;
}
