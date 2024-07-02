#include <stdio.h>
#define MAX 5

int a[MAX], front = -1, rear = -1;

void enqueue(int ele) {
  if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
    printf("Queue is overflow\n");
  } else {
    if (front == -1)
      front = 0;
    rear = (rear + 1) % MAX;
    a[rear] = ele;
  }
}

int dequeue() {
  int dele;
  if (front == -1) {
    printf("Queue is empty\n");
    return -1;
  } else {
    dele = a[front];
    if (front == rear) { // Check if there's only one element in the queue
      front = -1;
      rear = -1;
    } else {
      front = (front + 1) % MAX;
    }
  }
  return dele;
}

void display() {
  int i;
  if ((front == -1) && (rear == -1))
    printf("Empty queue\n");
  else {
    for (i = front; i != rear; i = (i + 1) % MAX) {
      printf("%d ", a[i]);
    }
    printf("%d ", a[i]); // Display the last element
  }
}

int main() {
  enqueue(40);
  enqueue(50);
  dequeue();
  display();
  return 0;
}
