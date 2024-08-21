#include <stdio.h>
#include <math.h>

// Structure to represent a polynomial term
typedef struct Term {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
} Term;

// Function to evaluate the polynomial
int evaluatePolynomial(Term poly[], int n, int x) {
    int result = 0;

    // Evaluate each term and add to the result
    for (int i = 0; i < n; i++) {
        result += poly[i].coeff * pow(x, poly[i].exp);
    }

    return result;
}

int main() {
    int n, x;

    // Input the number of terms in the polynomial
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    Term poly[n];

    // Input the terms of the polynomial
    printf("Enter the terms of the polynomial (coefficient and exponent):\n");
    for (int i = 0; i < n; i++) {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &poly[i].coeff, &poly[i].exp);
    }

    // Input the value of x
    printf("Enter the value of x to evaluate the polynomial: ");
    scanf("%d", &x);

    // Evaluate the polynomial
    int result = evaluatePolynomial(poly, n, x);

    // Print the result
    printf("The value of the polynomial at x = %d is: %d\n", x, result);

    return 0;
}
