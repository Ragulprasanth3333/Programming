#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;
int choice = 1, count = 0;

void push() {
    struct node *newnode;
    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL; 

        if (count == 0) {
            top = newnode;
        } else {
            newnode->next = top;  
            top = newnode;       
        }
        count += 1;

        printf("Press 1 to add more data, 0 to stop: ");
        scanf("%d", &choice);
    }
}

void pop() {
    if (top == NULL) {
        printf("The stack is empty\n");
        return;
    }
    struct node *temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next;
    free(temp);
    count -= 1;
}

void peek() {
    if (top == NULL) {
        printf("The stack is empty\n");
        return;
    } else {
        printf("Top element: %d\n", top->data);
    }
}

void display() {
    if (top == NULL) {
        printf("The stack is empty\n");
        return;
    } else {
        struct node *temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    push();
    pop();
    peek();
    display();
    return 0;
}
