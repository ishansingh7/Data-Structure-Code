#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert_at_beg(struct node **v, int d)
{
    struct node *nn;
    nn = (struct node *)malloc(sizeof(struct node));
    if (nn == NULL) 
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
else{
    nn->data = d;
    nn->next = *v;
    (*v) = nn;
}
}
int main()
{
    struct node *head = NULL;
    insert_at_beg(&head, 12);
    return 0;
}
