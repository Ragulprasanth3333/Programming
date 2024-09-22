#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *back = 0;
int count = 0;

void circular_queue() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == 0) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    if (back == 0) {
        back = newnode;
        back->next = back;  // Circular link to itself
    } else {
        newnode->next = back->next;
        back->next = newnode;
        back = newnode;
    }
}

void inseratend(int data) {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == 0) {
        printf("Memory allocation failed.\n");
        return;
    }

    newnode->data = data;
    
    if (back == 0) {
        back = newnode;
        back->next = back;  // First node, points to itself
    } else {
        temp = back->next;
        while (temp->next != back->next) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = back->next;
        back = newnode;
    }
}

void delbeg() {
    if (back == 0) {
        printf("The list is empty.\n");
        return;
    }

    if (back->next == back) {
        printf("The list has only one node. Deleting it.\n");
        free(back);
        back = 0;
        return;
    }

    struct node *temp = back->next;
    back->next = temp->next;
    free(temp);
}

void display() {
    if (back == 0) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = back->next;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != back->next);
    printf("(circular back to head)\n");
}

int main() {
    int choice = 1;

    while (choice) {
        circular_queue();
        printf("To add another node, press 1; to exit, press 0: ");
        scanf("%d", &choice);
        count++;
    }

    inseratend(30);
    inseratend(40);
    inseratend(50);
    inseratend(60);
    inseratend(70);
    delbeg();
    display();

    return 0;
}
