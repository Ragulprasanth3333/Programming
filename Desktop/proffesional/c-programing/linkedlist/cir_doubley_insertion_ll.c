#include <stdio.h>
#include <stdlib.h>

int choice = 1, count = 0;

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
        count += 1;
    }
}

void insatbeg(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL) {
        head = tail = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    } else {
        newnode->next = head;
        newnode->prev = tail;
        tail->next = newnode;
        head->prev = newnode;
        head = newnode;
    }
    count += 1;
}

void insatend(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL) {
        insatbeg(data);
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
        tail = newnode;
    }
    count += 1;
}

void insatpos(int data, int pos) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (head == NULL || pos == 1) {
        insatbeg(data);
    } else if (pos == count + 1) {
        insatend(data);
    } else if (pos > 1 && pos <= count) {
        struct node *temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
        count += 1;
    } else {
        printf("Invalid position!\n");
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
    insatbeg(20);
    insatend(30);
    insatpos(25, 2);
    printList();
    return 0;
}
