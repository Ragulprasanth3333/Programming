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
        count++;
    }
}

void delbeg() {
    if (head == NULL) {
        printf("The list is empty\n");
    } else if (head == tail) {  // Only one node
        free(head);
        head = tail = NULL;
    } else {
        struct node *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
        count--;
    }
}

void delend() {
    if (head == NULL) {
        printf("The list is empty\n");
    } else if (head == tail) {  // Only one node
        free(head);
        head = tail = NULL;
    } else {
        struct node *temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
        count--;
    }
}

void delatpos(int pos) {
    if (head == NULL) {
        printf("The list is empty\n");
    } else if (pos < 1 || pos > count) {
        printf("Invalid position\n");
    } else if (pos == 1) {
        delbeg();
    } else if (pos == count) {
        delend();
    } else {
        struct node *temp = head;
        int i;
        for (i = 1; i < pos; i++) {
            temp = temp->next;
        }
        struct node *prevs = temp->prev;
        struct node *nextnode = temp->next;
        prevs->next = nextnode;
        nextnode->prev = prevs;
        free(temp);
        count--;
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
    delbeg();        
    printList();    

    delend();        
    printList();     

    delatpos(2);     
    printList();     

    return 0;
}
