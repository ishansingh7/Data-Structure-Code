#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void node_creation(struct node **head, int d) {
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    if (nn == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    nn->data = d;
    nn->next = *head;
    *head = nn;
}

void insertion_begin(struct node **head, int d) {
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    if (nn == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    nn->data = d;
    nn->next = *head;
    *head = nn;
}

void insert_end(struct node **head, int d) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    if (nn == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    nn->data = d;
    nn->next = NULL;
    if (*head == NULL) {
        *head = nn;
    } else {
        struct node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = nn;
        nn->next = *head;
    }
}
void deleteatbeg(struct node**head){
    if(*head ==NULL){
        printf("List is empty\n");
        return;
    }
    struct node*temp =*head;
    *head = temp->next;
    free(temp);
}
void  deleteatend(struct node**head){
struct node *temp,*prev;
temp = *head;
if(*head == NULL){
    printf("List is empty\n");
    return;
}
while(temp->next !=*head){
    prev=temp;
    temp = temp->next;
}
prev->next =(*head)->next;
free(temp);
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
    int n, data;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        node_creation(&head, data);
    }
    
    printf("Enter data for node to be inserted at the beginning: ");
    scanf("%d", &data);
    insertion_begin(&head, data);
    
    printf("Enter data for node to be inserted at the end: ");
    scanf("%d", &data);
    insert_end(&head, data);

    
    printf("display before deleteatbegin, display: ");
    display(head);

    deleteatbeg(&head);

      
    
    printf("Displaying the list after deletion : ");
    
 deleteatend(&head);
    display(head);

    return 0;
}
