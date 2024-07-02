#include<stdio.h>
#define size 10
int stack[size],top=-1; 
void push(int val)
{
    if(top==size-1)
        printf("overflow");
    else {
        top++;
        stack[top]=val;
    }
}
int pop()
{
    int val;
    if(top==-1) {
        printf("underflow");
        return -1; 
    }
    else {
        val=stack[top];
        top--;
    }
    return val;
}
void display()
{
    int i;
    if(top==-1)
        printf("stack is empty");
    else {
        for(i=top; i>=0; i--) 
            printf(" %d\n",stack[i]);
    }
}
int main(){
    push(50);
    push(60);
    push(70);
    push(80);
    pop();
    // printf("the deleted elements is  : %d",pop());
    display();
    return 0;
}
