#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create() {
    int data;
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data or -1 for 0: ");
    scanf("%d", &data);
    if (data == -1) {
        return 0;
    }
    newnode->data = data;
    printf("Enter the left child of %d: ", data);
    newnode->left = create();
    printf("Enter the right child of %d: ", data);
    newnode->right = create();
    return newnode;
}

void preorder(struct node * root)
{
    if (root == 0)
    {return;}
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node * root)
{
    if (root == 0)
    {return;}
    
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
void postorder(struct node * root)
{
    if (root == 0)
    {return;}
    
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

int main() {
    struct node* root;
    root = create();
    printf("preorder traversal of the binary tree: ");
    preorder(root);
    printf("inorder traversal of the binary tree: ");
    inorder(root);
    printf("postorder traversal of the binary tree: ");
    postorder(root);
    return 0;
}
