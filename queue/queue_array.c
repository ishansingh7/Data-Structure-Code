#include<stdio.h>
#define max 5
int Q[max], front=-1, rear=-1;


void enqueue(int value){
    if(rear==max-1)
    printf("OVERFLOW");
    else if(front==-1)
    front=0;
    rear++;
    Q[rear]=value;
}
int dequeue(){
    if(front ==-1 && rear ==-1){
        printf("EMPTY QUEUE");
        return -1;
    }
    else if(front==rear)
    front=rear=-1;
    int deleted=Q[front];
    front++;
    return deleted;
}
void display(){
    if(front ==-1 && rear ==-1){
        printf("EMPTY QUEUE");
        return;
    }
    for(int i=front;i<=rear;i++){
        printf("%d\n",Q[i]);
    }
}

int main(){
    enqueue(45);
    enqueue(50);
    enqueue(60);
    enqueue(66);
    dequeue();
    display();
    return 0;
}