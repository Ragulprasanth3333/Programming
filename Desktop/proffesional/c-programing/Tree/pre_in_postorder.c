#include<stdio.h>
#include<stdlib.h>

struct node 
{
  int data;
  struct node *left;
  struct node * right;
};
struct node * create()
{
    int x;
    struct node* newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data or -1  ");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter the left child of %d\n",x);
    newnode->left=create();
    printf("Enter the right child of %d\n",x);
    newnode->right=create();
    return newnode;
}
void inorder(struct node * root)
{
    if(root==0)
    {
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if(root==0)
    {
        return;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if(root ==0)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
    
}
void main()
{
    struct node *root;
    root = create();
    printf("\npreorder traversal is ");
    preorder(root);
    printf("\ninorder traversal is ");
    inorder(root);
    printf("\npostorder traversal is ");
    postorder(root);
}