#include <stdio.h>
#include <stdlib.h>
struct node {
        int data;
        struct node *next;
    };
struct node *head = NULL, *temp = NULL, *newnode;
void linked() {
    
    int val;

    while(1) {
        printf("Create another node? Press 1 to continue or 0 to exit: ");
        scanf("%d", &val);
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

//to count single linklist
void count()
{
    struct node *temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count +=1;
        temp = temp->next;
    }
    printf("The number of list are : %d",count);
}
// to reverse node in link list
void revnode()
{
    struct node *prevnode,*currnode,*nextnode;
    prevnode = 0;
    currnode=nextnode=head;
    while(nextnode !=0)
    {
        nextnode = nextnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    head = prevnode;
}
int main()
{
    linked();
    count();
    revnode();
}