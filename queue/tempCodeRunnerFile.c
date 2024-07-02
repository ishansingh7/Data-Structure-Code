#include <stdio.h>
# define max 5
int Q[max];
int front = -1, rear = -1;

void enqueue(int x){
  if(rear== max -1){
    printf("Queue is full");
  }
  else if(front == -1){
    front= 0;
    rear++;
    Q[rear]=x;
  }
}
int dequeue(){
  if(front == -1 && rear ==-1){
    printf("Queue is empty");
    return -1;
  }
  else if(front == rear){
    front = rear = -1;
    
    int delete =Q[front];
    front++;
    return delete;
    
  }
}

void display(){
  if(front == -1 && rear==-1){
    printf("Queue is empty");
    return;
  }
  for(int i = front;i <=rear; i++){
    printf("%d\n",Q[i]);
  }
}

int main(void) {
  enqueue(45);
  enqueue(65);
  enqueue(55);
  enqueue(66);
  //enqueue(33);
  dequeue();
 
  display();
  return 0;
}