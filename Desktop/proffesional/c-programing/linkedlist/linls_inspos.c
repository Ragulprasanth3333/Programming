#include <stdio.h>
#include <stdlib.h>
struct node {
        int data;
        struct node *next;
    };
struct node *head = NULL, *temp = NULL, *newnode;
int count;
void linked() {
    
    int val;

    while(1) {
        printf("Create another node? Press 1 to continue or 0 to exit: ");
        scanf("%d", &val);
        count+=1;
        if(val == 0) {
            break;
        }

        // Allocate memory for the new node
        newnode = (struct node*) malloc(sizeof(struct node));
        
        if(newnode == NULL) {
            printf("Memory not allocated.\n");
            exit(1);
        }

        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    // Print the linked list
    temp = head;
    printf("The linked list is: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void insert(int data) {
    struct node *newnode;

    // Allocate memory for the new node
    newnode = (struct node*) malloc(sizeof(struct node));

    if(newnode == NULL) {
        printf("Memory not allocated.\n");
        exit(1);
    }

    // Set the data and the next pointer
    newnode->data = data;
    newnode->next = head;

    // Move the head to point to the new node
    head = newnode;
}
void insertend (int data)
{
   struct node *newnode,*temp;

    // Allocate memory for the new node
    newnode = (struct node*) malloc(sizeof(struct node));

    if(newnode == NULL) {
        printf("Memory not allocated.\n");
        exit(1);
    }

    // Set the data and the next pointer
    newnode->data = data;
    newnode->next = 0;
    temp = head;
    while(temp->next !=0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    
}
void insertpos(int data, int position) {
    struct node *newnode, *temp;
    newnode = (struct node*) malloc(sizeof(struct node));

    if(newnode == NULL) 
    {  
        printf("Memory not allocated.\n");
        exit(1);
    }

    newnode->data = data;

    if(position > count || position < 1) 
    { 
        printf("Invalid position\n");
        return;
    }

    if(position == 1) 
    {
        newnode->next = head;
        head = newnode;
    } 
    else
    {
        temp = head;
        for(int i = 1; i < position -1 ; i+=1) 
        { 
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    count += 1;
}
    
int main() {
    linked();
    insert(500);
    insertend(800);
    insertpos(5, 3); 
    struct node *temp = head;
    printf("The linked list after insertion is: ");
    while(temp != NULL) 
    {  
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}