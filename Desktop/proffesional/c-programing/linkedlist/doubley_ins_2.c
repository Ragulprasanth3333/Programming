#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

// Declare the head and temp pointers globally
struct node *head = NULL, *temp = NULL;

// Function to find the length of the linked list
int lenln() {
    int length = 0;
    temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

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


// Insert at a specific position
void insertatpos(int pos, int data) {
    int length = lenln();

    if (pos > length + 1 || pos < 1) {
        printf("INVALID POSITION\n");
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (pos == 1) {
        insertbeg(data);
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
}

// Insert after a specific position
void insertataftpos(int pos, int data) {
    int length = lenln();

    if (pos > length || pos < 1) {
        printf("INVALID POSITION\n");
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;

    temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
}

// Print the linked list
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
    insertatpos(2, 10);   // Insert 10 at position 2
    insertataftpos(2, 15); // Insert 15 after position 2
    printList(); // Print the linked list
    return 0;
}
