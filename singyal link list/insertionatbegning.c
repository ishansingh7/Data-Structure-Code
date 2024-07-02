#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void node_creation(struct node **head, int d) {
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    if (nn == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    nn->data = d;
    nn->next = NULL;
    *head = nn;
}

void insertion(struct node **head, int d) {
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    if (nn == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    nn->data = d;
    nn->next = *head;
    *head = nn;
}

void append(struct node **head, int d) {
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    if (nn == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    nn->data = d;
    nn->next = NULL;
   
    if (*head == NULL) {
        *head = nn;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nn;
}

void display(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int data;

    printf("Enter the node you want to add: ");
    scanf("%d", &data);

    node_creation(&head, data);
    display(head);

    printf("Enter the node you want to add: ");
    scanf("%d", &data);

    insertion(&head, data);
    display(head);

    printf("Enter the node you want to add: ");
    scanf("%d", &data);

    append(&head, data);
    display(head);

    return 0;
}
