#include <stdio.h>
#include <stdlib.h>

// Structure to represent a polynomial term
typedef struct Term {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
} Term;

// Function to add two polynomials
void addPolynomials(Term poly1[], int n1, Term poly2[], int n2, Term result[], int *n3) {
    int i = 0, j = 0, k = 0;

    // Traverse both polynomials
    while (i < n1 && j < n2) {
        if (poly1[i].exp > poly2[j].exp) {
            result[k++] = poly1[i++];
        } else if (poly1[i].exp < poly2[j].exp) {
            result[k++] = poly2[j++];
        } else {
            // Exponents are equal, add coefficients
            result[k].exp = poly1[i].exp;
            result[k++].coeff = poly1[i++].coeff + poly2[j++].coeff;
        }
    }

    // If there are remaining terms in poly1
    while (i < n1) {
        result[k++] = poly1[i++];
    }

    // If there are remaining terms in poly2
    while (j < n2) {
        result[k++] = poly2[j++];
    }

    *n3 = k;  // Number of terms in the result polynomial
}

int main() {
    int n1, n2, n3;

    // Input for the first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    Term poly1[n1];
    printf("Enter the terms of the first polynomial (coefficient and exponent):\n");
    for (int i = 0; i < n1; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly1[i].coeff, &poly1[i].exp);
    }

    // Input for the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    Term poly2[n2];
    printf("Enter the terms of the second polynomial (coefficient and exponent):\n");
    for (int i = 0; i < n2; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly2[i].coeff, &poly2[i].exp);
    }

    // Resultant polynomial can have at most n1 + n2 terms
    Term result[n1 + n2];

    // Add the two polynomials
    addPolynomials(poly1, n1, poly2, n2, result, &n3);

    // Print the resultant polynomial
    printf("Resultant polynomial:\n");
    for (int i = 0; i < n3; i++) {
        printf("%d*x^%d", result[i].coeff, result[i].exp);
        if (i < n3 - 1) {
            printf(" + ");
        }
    }
    printf("\n");

    return 0;
}
