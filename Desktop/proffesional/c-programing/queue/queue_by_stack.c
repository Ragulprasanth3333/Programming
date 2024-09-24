#include <stdio.h>
#include <stdlib.h>

#define N 6
int s1[N], s2[N];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data) {
    if (top1 == N - 1) {
        printf("Queue is full\n");
    } else {
        top1 += 1;
        s1[top1] = data;
    }
}

void push2(int data) {
    if (top2 == N - 1) {
        printf("Stack2 is full\n");
    } else {
        top2 += 1;
        s2[top2] = data;
    }
}

int pop1() {
    if (top1 == -1) {
        printf("Stack1 is empty\n");
        return -1;
    } else {
        int temp = s1[top1];
        top1 -= 1;
        return temp;
    }
}

int pop2() {
    if (top2 == -1) {
        printf("Stack2 is empty\n");
        return -1;
    } else {
        int temp = s2[top2];
        top2 -= 1;
        return temp;
    }
}

void enqueue(int data) {
    push1(data);
    count += 1;
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    if (top2 == -1) {
        // Transfer all elements from s1 to s2
        while (top1 != -1) {
            int val = pop1();
            push2(val);
        }
    }
    
    int dequeued_value = pop2();
    if (dequeued_value != -1) {
        printf("Dequeued element: %d\n", dequeued_value);
        count -= 1;
    }
}

void display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = 0; i <= top2; i++) {
            printf("%d ", s2[i]);
        }
        for (int i = top1; i >= 0; i--) {
            printf("%d ", s1[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}
