#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specified position
void insertNode(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node from a specified position
void deleteNode(Node** head, int position) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Function to count the number of nodes
int countNodes(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to reverse print the linked list
void reversePrint(Node* head) {
    if (head == NULL) return;
    reversePrint(head->next);
    printf("%d ", head->data);
}

// Function to reverse the linked list
void reverseList(Node** head) {
    Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertNode(&head, 10, 0);
    insertNode(&head, 20, 1);
    insertNode(&head, 30, 2);
    printf("List: ");
    printList(head);

    deleteNode(&head, 1);
    printf("After deletion: ");
    printList(head);

    printf("Count of nodes: %d\n", countNodes(head));

    printf("Reverse print: ");
    reversePrint(head);
    printf("\n");

    reverseList(&head);
    printf("Reversed list: ");
    printList(head);

    return 0;
}
