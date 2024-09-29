#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create() {
    int x;
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data or -1 for 0: ");
    scanf("%d", &x);
    if (x == -1) {
        return 0;
    }
    newnode->data = x;
    printf("Enter the left child of %d: ", x);
    newnode->left = create();
    printf("Enter the right child of %d: ", x);
    newnode->right = create();
    return newnode;
}

void inorder(struct node* root) {
    if (root == 0) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node* root;
    root = create();
    printf("Inorder traversal of the binary tree: ");
    inorder(root);
    return 0;
}
