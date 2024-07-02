#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node*next;
};
struct node*front=NULL;
struct node*rear=NULL;

void enqueue(int val)
{
    struct node *nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->data=val;
    nn->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=nn;
        return;
    }
    rear->next=nn;
    rear=nn;
}
void dequeue(){
struct node *temp;
temp=front;
if(front==NULL && rear==NULL)//Empty queue or only one node
    {
    printf("Queue is Empty");
    return;
}
    else//Many nodes are there
        {
        front=front->next;
    }
        free(temp);//freeing the node pointed by front

}

void display(){
    struct node*temp;
temp=front;
while(temp!=rear){
    printf("%d ",temp->data);
    temp=temp->next;
}
printf("%d ",temp->data);
  }


int main(){
    enqueue(34);
    enqueue(78);
    enqueue(90);
    enqueue(38);
    enqueue(29);
    dequeue();
    display();
 return 0;
}