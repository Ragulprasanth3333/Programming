#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to create a linked list
void linkedlist() {
    struct node *newnode, *temp;
    int choice = 1;

    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("To create another node, press 1; to exit, press 0: ");
        scanf("%d", &choice);
    }
}

// Function to delete a node from a specific position
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("The list is empty, no node to delete.\n");
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    if (position == 1) {
        head = head->next;
        free(temp);
        printf("Deleted node at position 1.\n");
        return;
    }

    int i;
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d does not exist.\n", position);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted node at position %d.\n", position);
}

// Function to print the linked list
void printList() {
    struct node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    linkedlist();
    printList();
    
    int position;
    printf("Enter the position to delete the node: ");
    scanf("%d", &position);
    
    deleteAtPosition(position);
    printList();
    
    return 0;
}