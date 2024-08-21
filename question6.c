#include <stdio.h>
#include <stdlib.h>

// Node structure for sparse matrix
typedef struct Node {
    int row, col, value;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the linked list
Node* addNode(Node* head, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);
    if (!head) return newNode;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to add two sparse matrices
Node* addSparseMatrices(Node* mat1, Node* mat2) {
    Node *result = NULL, *temp1 = mat1, *temp2 = mat2;

    while (temp1 || temp2) {
        if (!temp2 || (temp1 && temp1->row < temp2->row) || (temp1->row == temp2->row && temp1->col < temp2->col)) {
            result = addNode(result, temp1->row, temp1->col, temp1->value);
            temp1 = temp1->next;
        } else if (!temp1 || (temp2 && temp2->row < temp1->row) || (temp1->row == temp2->row && temp2->col < temp1->col)) {
            result = addNode(result, temp2->row, temp2->col, temp2->value);
            temp2 = temp2->next;
        } else {
            result = addNode(result, temp1->row, temp1->col, temp1->value + temp2->value);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return result;
}

// Function to print the sparse matrix
void printSparseMatrix(Node* head) {
    while (head) {
        printf("Row: %d, Col: %d, Value: %d\n", head->row, head->col, head->value);
        head = head->next;
    }
}

int main() {
    Node *mat1 = NULL, *mat2 = NULL;

    // Adding elements to the first sparse matrix
    mat1 = addNode(mat1, 0, 1, 5);
    mat1 = addNode(mat1, 1, 2, 8);
    mat1 = addNode(mat1, 3, 0, 6);

    // Adding elements to the second sparse matrix
    mat2 = addNode(mat2, 0, 1, 3);
    mat2 = addNode(mat2, 2, 2, 7);
    mat2 = addNode(mat2, 3, 0, 4);

    // Adding the two sparse matrices
    Node* result = addSparseMatrices(mat1, mat2);

    // Printing the result
    printf("Resultant Sparse Matrix:\n");
    printSparseMatrix(result);

    return 0;
}
