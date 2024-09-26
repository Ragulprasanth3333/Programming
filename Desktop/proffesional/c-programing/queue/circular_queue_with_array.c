#include <stdio.h>
#define N 5

int deque[N], front = -1, back = -1;

void enqueuefront(int data) {
    if ((front == back + 1) || (front == 0 && back == N - 1)) {
        printf("The queue is full\n");
    } else if (front == -1 && back == -1) {
        front = back = 0;
        deque[front] = data;
    } else if (front == 0) {
        front = N - 1;
        deque[front] = data;
    } else {
        front -= 1;
        deque[front] = data;
    }
}

void enqueueback(int data) {
    if ((front == back + 1) || (front == 0 && back == N - 1)) {
        printf("The queue is full\n");
    } else if (front == -1 && back == -1) {
        front = back = 0;
        deque[back] = data;
    } else if (back == N - 1) {
        back = 0;
        deque[back] = data;
    } else {
        back += 1;
        deque[back] = data;
    }
}

void dequeuefront() {
    if (front == -1 && back == -1) {
        printf("The queue is empty\n");
    } else if (front == back) {
        front = back = -1;
    } else if (front == N - 1) {
        front = 0;
    } else {
        front += 1;
    }
}

void dequeueback() {
    if (front == -1 && back == -1) {
        printf("The queue is empty\n");
    } else if (front == back) {
        front = back = -1;
    } else if (back == 0) {
        back = N - 1;
    } else {
        back -= 1;
    }
}

void display() {
    if (front == -1) {
        printf("The queue is empty\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while (i != back) {
            printf("%d ", deque[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", deque[back]);
    }
}

int main() {
    enqueuefront(1);
    enqueueback(2);
    enqueuefront(3);
    enqueuefront(5);
    enqueueback(7);
    enqueuefront(9);
    display();
    dequeuefront();
    display();
    dequeueback();
    display();
    return 0;
}
