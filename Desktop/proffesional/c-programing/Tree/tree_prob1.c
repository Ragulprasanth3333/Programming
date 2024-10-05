// constructing binary tree from pre-order and In-order arrays
#include <stdio.h>
#include <stdlib.h>


int preorder[11] = {1, 2, 4, 9, 8, 10, 11, 5, 3, 6, 7};
int inorder[11] = {8, 4, 10, 9, 11, 2, 5, 1, 6, 3, 7};

// Node structure for binary tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = 0;
    return newnode;
}

// Function to find index of a value in an array
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Function to construct binary tree from pre-order and in-order
struct node* constructTree(int inorder[], int preorder[], int inorderStart, int inorderEnd, int *preorderIndex) {
    if (inorderStart > inorderEnd)
        return 0;

    // Create a new node with current root from pre-order traversal
    struct node* root = createNode(preorder[*preorderIndex]);
    (*preorderIndex)++;

    // If the node has no children, return it
    if (inorderStart == inorderEnd)
        return root;

    // Find the index of this root in in-order array
    int inorderIndex = findIndex(inorder, inorderStart, inorderEnd, root->data);

    // Construct left and right subtrees recursively
    root->left = constructTree(inorder, preorder, inorderStart, inorderIndex - 1, preorderIndex);
    root->right = constructTree(inorder, preorder, inorderIndex + 1, inorderEnd, preorderIndex);

    return root;
}

// Function to print the tree in in-order fashion (for validation)
void printInOrder(struct node* node) {
    if (node == 0)
        return;
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

int main() {
    int preorderIndex = 0;
    int length = sizeof(inorder) / sizeof(inorder[0]);

    // Construct the tree
    struct node* root = constructTree(inorder, preorder, 0, length - 1, &preorderIndex);

    // Print in-order traversal to validate the constructed tree
    printf("In-order traversal of the constructed tree:\n");
    printInOrder(root);

    return 0;
}
