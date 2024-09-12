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

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a key in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Function to find the minimum value node (used for finding successor)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to find in-order predecessor and successor
void findPreSuc(struct Node* root, struct Node** pre, struct Node** suc, int key) {
    if (root == NULL) {
        return;
    }

    // If the key is found
    if (root->data == key) {
        // Find the predecessor (maximum value in the left subtree)
        if (root->left != NULL) {
            struct Node* temp = root->left;
            while (temp->right != NULL) {
                temp = temp->right;
            }
            *pre = temp;
        }

        // Find the successor (minimum value in the right subtree)
        if (root->right != NULL) {
            struct Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            *suc = temp;
        }
        return;
    }

    // If the key is smaller than root's data, go left
    if (key < root->data) {
        *suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    // If the key is greater than root's data, go right
    else {
        *pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    // Recur down the tree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// In-order traversal (for verification)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, data, key;
    struct Node* pre = NULL;
    struct Node* suc = NULL;
    
    do {
        printf("\nMenu:\n");
        printf("1. Create/Insert a node in the BST\n");
        printf("2. Search a key in the BST\n");
        printf("3. Find in-order Predecessor and Successor of a key\n");
        printf("4. Insert a key in the BST\n");
        printf("5. Delete a key from the BST\n");
        printf("6. Display In-order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("Key %d found in the BST.\n", key);
                } else {
                    printf("Key %d not found in the BST.\n", key);
                }
                break;
            case 3:
                printf("Enter the key to find Predecessor and Successor: ");
                scanf("%d", &key);
                pre = NULL;
                suc = NULL;
                findPreSuc(root, &pre, &suc, key);
                if (pre != NULL) {
                    printf("Predecessor of %d is %d\n", key, pre->data);
                } else {
                    printf("No Predecessor found for %d\n", key);
                }
                if (suc != NULL) {
                    printf("Successor of %d is %d\n", key, suc->data);
                } else {
                    printf("No Successor found for %d\n", key);
                }
                break;
            case 4:
                printf("Enter the key to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 5:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Key %d deleted from the BST.\n", key);
                break;
            case 6:
                printf("In-order Traversal of the BST: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 7);
    
    return 0;
}