#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to search for the index of a value in the in-order traversal
int search(int inOrder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inOrder[i] == value) {
            return i;
        }
    }
    return -1;
}

// Function to build the binary tree from in-order and pre-order traversals
struct Node* buildTree(int inOrder[], int preOrder[], int inStart, int inEnd, int *preIndex) {
    // Base case: If there are no elements to construct the tree
    if (inStart > inEnd) {
        return NULL;
    }

    // Select the current node from the pre-order traversal
    int currentData = preOrder[*preIndex];
    (*preIndex)++;

    // Create the new node
    struct Node* newNode = createNode(currentData);

    // If this node has no children, return it
    if (inStart == inEnd) {
        return newNode;
    }

    // Find the index of this node in the in-order traversal
    int inIndex = search(inOrder, inStart, inEnd, currentData);

    // Recursively build the left and right subtrees
    newNode->left = buildTree(inOrder, preOrder, inStart, inIndex - 1, preIndex);
    newNode->right = buildTree(inOrder, preOrder, inIndex + 1, inEnd, preIndex);

    return newNode;
}

// Function to perform in-order traversal and print the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    int n;

    // Input size of the tree
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int inOrder[n], preOrder[n];
    
    // Input in-order traversal
    printf("Enter the in-order traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inOrder[i]);
    }
    
    // Input pre-order traversal
    printf("Enter the pre-order traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preOrder[i]);
    }

    int preIndex = 0;  // Initial index for pre-order traversal

    // Build the tree
    struct Node* root = buildTree(inOrder, preOrder, 0, n - 1, &preIndex);

    // Print the in-order traversal of the constructed tree
    printf("In-order traversal of the constructed tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}