//constructing binary tree from postorder and inorder
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = 0;
    return newNode;
}

// Find index of a value in an array (helper function)
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Function to construct the binary tree from post-order and in-order traversals
struct node* constructTree(int inorder[], int postorder[], int inorderStart, int inorderEnd, int* postorderIndex) {
    if (inorderStart > inorderEnd)
        return 0;

    // Get the current root from post-order traversal
    struct node* root = createNode(postorder[*postorderIndex]);
    (*postorderIndex)--;

    // If the tree has only one element
    if (inorderStart == inorderEnd)
        return root;

    // Find the index of the current root in the in-order array
    int inorderIndex = findIndex(inorder, inorderStart, inorderEnd, root->data);

    // Construct right and left subtrees recursively
    root->right = constructTree(inorder, postorder, inorderIndex + 1, inorderEnd, postorderIndex);
    root->left = constructTree(inorder, postorder, inorderStart, inorderIndex - 1, postorderIndex);

    return root;
}

// Function to print the tree in-order (for validation)
void printInOrder(struct node* node) {
    if (node == 0)
        return;
    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

int main() {
    int postorder[] = {9, 1, 2, 12, 7, 5, 3, 11, 4, 8};
    int inorder[] = {9, 5, 1, 7, 2, 12, 8, 4, 3, 11};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    int postorderIndex = n - 1;  // Start from the last element in post-order

    struct node* root = constructTree(inorder, postorder, 0, n - 1, &postorderIndex);

    printf("In-order traversal of the constructed tree:\n");
    printInOrder(root);

    return 0;
}
