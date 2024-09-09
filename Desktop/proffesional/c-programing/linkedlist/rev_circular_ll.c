#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *tail = NULL;
int count = 0;

void circular_ln() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    if (tail == NULL) {
        tail = newnode;
        tail->next = tail;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void printls() {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = tail->next;  
    
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);

    printf("(circular back to head)\n");
}

void rev() {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *prev = tail, *curr = tail->next, *nextnode = NULL;
    struct node *head = tail->next;  // Save the head (which is tail->next)

    do {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    } while (curr != head);  
    head->next = prev; 
    tail = head;  
}


int main() {
    int choice = 1;

    while (choice) {
        circular_ln();
        printf("To add another node, press 1; to exit, press 0: ");
        scanf("%d", &choice);
        count += 1;
    }
    rev();
    printls();
    return 0;
}