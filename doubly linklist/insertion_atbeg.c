          #include<stdio.h>
          #include<stdlib.h>

          struct node {
              int data;
              struct node *next;
              struct node *prev;
          };

          void node_create(struct node **v, int d) {
              struct node *nn = (struct node*)malloc(sizeof(struct node));
              nn->data = d;
              nn->next = NULL;
              nn->prev = NULL;
              *v = nn;
          }

          void insertion_at_begin(struct node **v, int d) {
              struct node *nn = (struct node*)malloc(sizeof(struct node));
              nn->data = d;
              nn->prev = NULL;
              nn->next = NULL;
              if(*v == NULL) {
                  *v = nn;
              } else {
                  nn->next = *v;
                  (*v)->prev = nn;
                  *v = nn;
              }
          }

          void insertion_at_end(struct node **v, int d) {
              struct node *nn = (struct node*)malloc(sizeof(struct node));
              nn->data = d;
              nn->prev = NULL;
              nn->next = NULL;
              if(*v == NULL) {
                  *v = nn;
              } else {
                  struct node *temp = *v;
                  while(temp->next != NULL) {
                      temp = temp->next;
                  }
                  temp->next = nn;
                  nn->prev = temp;
              }
          }

          void insertion_at_pos(struct node **v, int d, int pos) {
              struct node *nn = (struct node*)malloc(sizeof(struct node));
              nn->data = d;
              nn->prev = NULL;
              nn->next = NULL;
              if(*v == NULL) {
                  *v = nn;
              } else {
                  struct node *temp = *v;
                  int count = 1;
                  while(temp != NULL && count < pos) {
                      temp = temp->next;
                      count++;
                  }
                  if(temp == NULL) {
                      printf("Invalid position\n");
                      free(nn);
                      return;
                  }
                  nn->next = temp->next;
                  nn->prev = temp;
                  if(temp->next != NULL) {
                      temp->next->prev = nn;
                  }
                  temp->next = nn;
              }
          }

          void display(struct node *v) {
              while (v != NULL) {
                  printf("%d ", v->data);
                  v = v->next;
              }
              printf("\n");
          }

          int main() {
              struct node *head = NULL;

              node_create(&head, 10);
              insertion_at_begin(&head, 20);
              insertion_at_begin(&head, 30);
              insertion_at_end(&head, 78);
              insertion_at_pos(&head, 40, 3); 

              printf("Doubly linked list: ");
              display(head);

              return 0;
          }
