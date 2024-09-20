#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = 0 , *back = 0;

void enqueue(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = 0;
    
    if (front == 0 && back == 0) {
        front = back = newnode;
    } else {
        back->next = newnode;
        back = newnode;
    }
}

void display() {
    struct node *temp = front;
    while (temp != 0) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void peek() {
    if (front == 0) {
        printf("The queue is empty\n");
    } else {
        printf("The peek of the queue is %d\n", front->data);
    }
}

void dequeue() {
    if (front == 0) {
        printf("The queue is empty\n");
    } else {
        struct node *temp = front;
        front = front->next;
        free(temp);
        if (front == 0) {
            back = 0;  // If the queue is empty after dequeue
        }
    }
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    display();
    peek();
}
