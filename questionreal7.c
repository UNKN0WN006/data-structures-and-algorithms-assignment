#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial term
typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node into the polynomial linked list
Node* insertNode(Node* head, int coefficient, int exponent) {
    Node* newNode = createNode(coefficient, exponent);
    if (!head) return newNode;

    Node* temp = head;
    Node* prev = NULL;
    while (temp && temp->exponent > exponent) {
        prev = temp;
        temp = temp->next;
    }

    if (temp && temp->exponent == exponent) {
        temp->coefficient += coefficient;
        free(newNode);
    } else {
        newNode->next = temp;
        if (prev) {
            prev->next = newNode;
        } else {
            head = newNode;
        }
    }

    return head;
}

// Function to multiply two sparse polynomials
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* ptr1 = poly1;
    Node* ptr2;

    while (ptr1) {
        ptr2 = poly2;
        while (ptr2) {
            int coeff = ptr1->coefficient * ptr2->coefficient;
            int exp = ptr1->exponent + ptr2->exponent;
            result = insertNode(result, coeff, exp);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return result;
}

// Function to print the polynomial
void printPolynomial(Node* head) {
    if (!head) {
        printf("0\n");
        return;
    }

    Node* temp = head;
    while (temp) {
        printf("%dx^%d", temp->coefficient, temp->exponent);
        if (temp->next) printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL;

    // Polynomial 1: 3x^3 + 2x^1 + 1
    poly1 = insertNode(poly1, 3, 3);
    poly1 = insertNode(poly1, 2, 1);
    poly1 = insertNode(poly1, 1, 0);

    // Polynomial 2: 4x^2 + 3x^1 + 2
    poly2 = insertNode(poly2, 4, 2);
    poly2 = insertNode(poly2, 3, 1);
    poly2 = insertNode(poly2, 2, 0);

    // Multiply the polynomials
    Node* result = multiplyPolynomials(poly1, poly2);

    // Print the result
    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    printf("Result: ");
    printPolynomial(result);

    return 0;
}
