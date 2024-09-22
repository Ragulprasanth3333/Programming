#include <stdio.h>
#include <stdlib.h>

#define N 6
int arr[N], front = -1, back = -1;

void enqueue(int data)
{
    if ((back + 1) % N == front)
    {
        printf("Queue is full\n");
    }
    else if (front == -1 && back == -1)
    {
        front = back = 0;
        arr[back] = data;
    }
    else
    {
        back = (back + 1) % N;
        arr[back] = data;
    }
}

void dequeue()
{
    if (front == -1 && back == -1)
    {
        printf("The queue is empty\n");
    }
    else if (front == back)
    {
        printf("Dequeued element is %d\n", arr[front]);
        front = back = -1;
    }
    else
    {
        printf("Dequeued element is %d\n", arr[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    if (front == -1 && back == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int temp = front;
        printf("Queue elements: ");
        while (temp != back)
        {
            printf("%d ", arr[temp]);
            temp = (temp + 1) % N;
        }
        printf("%d\n", arr[back]);
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
    return 0;
}
