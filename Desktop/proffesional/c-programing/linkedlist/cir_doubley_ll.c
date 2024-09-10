#include <stdio.h>
#include <stdlib.h>

int choice = 1;

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void cir_ll() {
    struct node *newnode;
    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = 0; 
        if (head == NULL) {
            head = tail = newnode;
            newnode->next = newnode;
            newnode->prev = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            newnode->next = head;
            head->prev = newnode;
            tail = newnode;
        }
        printf("1 to add data, 0 to exit: ");
        scanf("%d", &choice); 
    }
}

void printList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("Circular Doubly Linked List: ");

    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head); 

    printf("(back to head)\n");
}

int main() {
    cir_ll();
    printList();
    return 0;
}