#include <stdio.h>
#include <stdlib.h>

// Declare tail globally so it can be used in multiple functions
struct node {
    int data;
    struct node *next;
};

struct node *tail = 0;

void circular_ln() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == 0) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    if (tail == 0) {
        // When the list is empty, initialize tail
        tail = newnode;
        tail->next = tail;  // Points to itself, making it circular
    } else {
        // Insert the new node at the end of the circular linked list
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;  // Update tail to the new node
    }
}

void printls() {
    if (tail == 0) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = tail->next;  // Start from the head (tail->next)
    
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);  // Stop when we complete the circle

    printf("(circular back to head)\n");
}

int main() {
    int choice = 1;

    // Continuously add nodes to the circular linked list
    while (choice) {
        circular_ln();
        printf("To add another node, press 1; to exit, press 0: ");
        scanf("%d", &choice);
    }

    printls();  // Print the circular linked list
    return 0;
}