#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void node_create(struct node **n, int d) {
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    if (nn == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    nn->data = d;
    nn->next = NULL;
    nn->prev = NULL;
    *n = nn;
}


void insert_at_beg(struct node **head, int d) {
    struct node *nn;
    nn = (struct node*)malloc(sizeof(struct node));
   nn->data =d;
   nn->prev =NULL;
   nn->next = NULL;
   if(*head == NULL){
    *head = nn;
   }
   else{
    nn->next = *head;
    (*head)->prev = nn;
    *head = nn;
   }
}


void display(struct node *nn) {
    while (nn != NULL) {
        printf("%d ", nn->data);
        nn = nn->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    
    
    node_create(&head, 8);
    insert_at_beg(&head, 5);
    insert_at_beg(&head, 9);

    printf("Doubly linked list: ");
    display(head);

    return 0;
}
