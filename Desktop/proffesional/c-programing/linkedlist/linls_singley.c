#include <stdio.h>
#include <stdlib.h>

void linkedlist() {
    struct node {
        int data;
        struct node *next;
    };

    struct node *head = NULL, *newnode, *temp;
    int choice = 1, count = 0;

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

    // Printing the linked list and counting nodes
    temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
    printf("Total number of nodes: %d\n", count);
}

int main() {
    linkedlist();
    return 0;
}