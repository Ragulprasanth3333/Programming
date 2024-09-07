#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head, *temp, *newnode;
int count = 0;

void ln() {
    int choice = 1;
    head = NULL;
    temp = NULL;

    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        
        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        count++;
        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &choice);
    }
}

void delatbeg() {
    if (head == NULL) {
        printf("There is no item in the list.\n");
        return;
    }
    struct node *todel = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(todel);
    count--;
}

void delatend() {
    if (head == NULL) {
        printf("There is no item in the list.\n");
        return;
    }

    temp = head;

    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        printf("The last item has been deleted.\n");
        count--;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    printf("The last item has been deleted.\n");
    count--;
}

void delatpos(int pos) {
    if (head == NULL) {
        printf("There is no item to delete.\n");
        return;
    }
    if (pos < 1 || pos > count) {
        printf("Invalid position.\n");
        return;
    }

    int i = 1;
    temp = head;

    if (pos == 1) {
        delatbeg();
        return;
    }

    if (pos == count) {
        delatend();
        return;
    }

    while (i < pos) {
        temp = temp->next;
        i++;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    count--;
}

void printls() {
    temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void revlis() {
    struct node *tail, *curr, *next;

    if (head == NULL) {
        printf("There is no node in the list\n");
        return; 
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    tail = temp; 

    curr = head;
    while (curr != NULL) {
        next = curr->next;
        curr->next = curr->prev;
        curr->prev = next;
        curr = next;
    }
    head = tail;
}


int main() {
    ln();
    printls();
    revlis();
    printls();
    return 0;
}