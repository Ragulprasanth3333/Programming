#include <stdio.h>
#define N 5
int queue[N];
int front = -1, back = -1;

void enqueue(int data) {
    if (back == N - 1) {
        printf("The queue is in overflow\n");
    } else if (front == -1 && back == -1) {
        front = back = 0;
        queue[back] = data;
    } else {
        back += 1;
        queue[back] = data;
    }
}

void dequeue() {
    if (front == -1 && back == -1) {
        printf("The queue is empty\n");
    } else if (front == back) {
        front = back = -1;
    } else {
        printf("The dequeued value is %d\n", queue[front]);
        front += 1;
    }
}

void peek() {
    if (front == -1 && back == -1) {
        printf("The queue is empty\n");
    } else {
        printf("%d\n", queue[front]);
    }
}

void display() {
    if (front == -1 && back == -1) {
        printf("The queue is empty\n");
    } else {
        for (int i = front; i <= back; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    display();
}
