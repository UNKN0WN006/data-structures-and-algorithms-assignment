#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void print2DFrom1D(Node* head, int m, int n) {
    Node* temp = head;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int index = i * n + j;
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    
    // Input the dimensions of the 2D array
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);

    // Create a linked list to store the 1D array elements
    Node* head = NULL;
    Node* tail = NULL;

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < m * n; i++) {
        int data;
        scanf("%d", &data);
        Node* newNode = createNode(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Print the 2D array using the 1D array indices
    printf("2D array from 1D array:\n");
    print2DFrom1D(head, m, n);

    return 0;
}
