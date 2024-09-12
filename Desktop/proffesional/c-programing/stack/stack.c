#include <stdio.h>
#include <stdlib.h>

int n = 5;
int stack[5];
int top = -1;

void push(int data) {
    if (top == n - 1) {
        printf("Overflow condition\n");
    } else {
        top += 1;
        stack[top] = data;
    }
}

void pop() {
    if (top == -1) {
        printf("The stack is empty\n");
    } else {
        int popped = stack[top];
        stack[top] = 0; // Optional: Reset value to 0
        top -= 1;
        printf("Popped element is: %d\n", popped);
    }
}

void peek() {
    if (top == -1) {
        printf("The stack is empty\n");
    } else {
        printf("Peek element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("The stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    push(5);
    push(4);
    push(3);
    push(2);
    pop();
    peek();
    display();
    
    return 0;
}
