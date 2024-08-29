#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a circular linked list with n nodes
Node* createCircularList(int n) {
    if (n <= 0) return NULL;
    Node* head = createNode(1);
    Node* temp = head;
    for (int i = 2; i <= n; i++) {
        temp->next = createNode(i);
        temp = temp->next;
    }
    temp->next = head; // Making it circular
    return head;
}

// Function to find the Josephus position
int josephus(int n, int k) {
    Node* head = createCircularList(n);
    Node *prev = NULL, *current = head;
    while (current->next != current) {
        // Traverse k-1 nodes
        for (int i = 1; i < k; i++) {
            prev = current;
            current = current->next;
        }
        // Remove current node
        prev->next = current->next;
        free(current);
        current = prev->next;
    }
    int result = current->data;
    free(current);
    return result;
}

int main() {
    int n, k;
    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the step count (k): ");
    scanf("%d", &k);

    int result = josephus(n, k);
    printf("The safe position is: %d\n", result);

    return 0;
}
