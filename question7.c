#include <stdio.h>

#define MAX 100  // Maximum number of non-zero elements

// Structure to store a non-zero element
typedef struct {
    int row;
    int col;
    int value;
} SparseMatrix;

// Function to add two sparse matrices
void addSparseMatrices(SparseMatrix mat1[], int size1, SparseMatrix mat2[], int size2, SparseMatrix result[], int *sizeResult) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (mat1[i].row < mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            result[k++] = mat1[i++];
        } else if (mat1[i].row > mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col > mat2[j].col)) {
            result[k++] = mat2[j++];
        } else {
            result[k].row = mat1[i].row;
            result[k].col = mat1[i].col;
            result[k].value = mat1[i].value + mat2[j].value;
            i++; j++; k++;
        }
    }

    while (i < size1) result[k++] = mat1[i++];
    while (j < size2) result[k++] = mat2[j++];

    *sizeResult = k;
}

// Function to print a sparse matrix
void printSparseMatrix(SparseMatrix mat[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Row: %d, Column: %d, Value: %d\n", mat[i].row, mat[i].col, mat[i].value);
    }
}

int main() {
    SparseMatrix mat1[MAX], mat2[MAX], result[MAX];
    int size1, size2, sizeResult;

    // Input size and elements for first sparse matrix
    printf("Enter number of non-zero elements in first matrix: ");
    scanf("%d", &size1);
    printf("Enter row, column, and value for each element:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d %d %d", &mat1[i].row, &mat1[i].col, &mat1[i].value);
    }

    // Input size and elements for second sparse matrix
    printf("Enter number of non-zero elements in second matrix: ");
    scanf("%d", &size2);
    printf("Enter row, column, and value for each element:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d %d %d", &mat2[i].row, &mat2[i].col, &mat2[i].value);
    }

    // Add the two sparse matrices
    addSparseMatrices(mat1, size1, mat2, size2, result, &sizeResult);

    // Print the result
    printf("Resultant Sparse Matrix:\n");
    printSparseMatrix(result, sizeResult);

    return 0;
}
