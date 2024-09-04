#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    struct node *prev;
    int data;
    struct node *next;
};

// Declare the head and temp pointers globally
struct node *head = NULL, *temp = NULL;

void lnd() {
    int choice = 1;
    
    while (choice) {
        // Allocate memory for the new node
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        
        // Check if memory allocation was successful
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter the data: ");
        scanf("%d", &newnode->data);

        // Initialize the new node's pointers
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            // If the list is empty, initialize head
            head = temp = newnode;
        } else {
            // Link the new node at the end of the list
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("To add another node, press 1; to exit, press 0: ");
        scanf("%d", &choice);
    }
}

// Function to print the doubly linked list
void printList() {
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

int main() {
    lnd();     // Create the linked list
    printList(); // Print the linked list

    return 0;
}