#include <stdio.h>

// Structure to represent a sparse matrix element
typedef struct {
    int row;
    int col;
    int value;
} Element;

// Function to count non-zero elements in each row
void countNonZeroInRows(Element mat[], int n, int rows) {
    int rowCount[rows];
    
    // Initialize rowCount array to 0
    for (int i = 0; i < rows; i++) {
        rowCount[i] = 0;
    }

    // Count non-zero elements in each row
    for (int i = 0; i < n; i++) {
        rowCount[mat[i].row]++;
    }

    // Print the result
    printf("Number of non-zero elements in each row:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: %d\n", i, rowCount[i]);
    }
}

int main() {
    int n, rows, cols;

    // Input the number of rows and columns in the matrix
    printf("Enter the number of rows and columns in the matrix: ");
    scanf("%d %d", &rows, &cols);

    // Input the number of non-zero elements in the sparse matrix
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &n);

    Element mat[n];

    // Input the non-zero elements
    printf("Enter the non-zero elements (row, col, value):\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &mat[i].row, &mat[i].col, &mat[i].value);
    }

    // Count and print the number of non-zero elements in each row
    countNonZeroInRows(mat, n, rows);

    return 0;
}
