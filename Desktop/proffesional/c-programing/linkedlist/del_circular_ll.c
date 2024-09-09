#include <stdio.h>
#include <stdlib.h>

// Declare tail globally so it can be used in multiple functions
struct node {
    int data;
    struct node *next;
};

struct node *tail = NULL;
int count=0;

void circular_ln() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter the data: ");
    scanf("%d", &newnode->data);

    if (tail == NULL) {
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
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = tail->next;  
    
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next); 

    printf("(circular back to head)\n");
}
void delbeg() {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (tail->next == tail) {
        printf("The list has only one node. Deleting it.\n");
        free(tail);
        tail = NULL;  
        return;
    }

   
    struct node *temp = tail->next;  
    tail->next = temp->next;         
    free(temp);       
}
void delend()
{
    struct node *temp;
    temp = tail;
    if(tail==NULL)
    {
        printf("The list is empty ");
        return;
    }
    if(tail->next==tail)
    {
        printf("There is only one node ");
        free(tail);
        tail=NULL;
        return;
    }
    else
    {
        struct node *temp = tail->next;  
        while (temp->next != tail)
        {    
            temp = temp->next;
        }

    
        temp->next = tail->next;  
        free(tail);               
        tail = temp;
        
    }
}

void delatpos(int pos)
{
    if (tail == NULL)
    {
        printf("The list is empty");
        return;
    }
    if( pos > count || pos < 0 )
    {
        printf("Invalid POSITION");
        return;
    }

    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        count-=1;
        return;
    }
    else
    {
        
        if (pos ==1)
        {
            delbeg();
            return;
        }
        else if(pos==count)
        {
            delend();
            return;
        }
        struct node *prev=NULL,*temp=tail->next;
        int i = 1;
        for (i;i<pos;i+=1)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
        count-=1;
    }
}

int main() {
    int choice = 1;

    // Continuously add nodes to the circular linked list
    while (choice) {
        circular_ln();
        printf("To add another node, press 1; to exit, press 0: ");
        scanf("%d", &choice);
        count +=1;
    }
    delbeg();
    delend();
    delatpos(2);
    printls();  // Print the circular linked list
    return 0;
}