#include <stdio.h>
#define MAX_TERMS 100

// Structure to represent a sparse matrix in triplet form
typedef struct {
    int row;
    int col;
    int value;
} Element;

// Structure to represent a sparse matrix
typedef struct {
    int rows;    // Total number of rows
    int cols;    // Total number of columns
    int numTerms;  // Number of non-zero elements
    Element data[MAX_TERMS];
} SparseMatrix;

// Function to read a sparse matrix
void readSparseMatrix(SparseMatrix *matrix) {
    printf("Enter the dimensions (rows columns): ");
    scanf("%d %d", &matrix->rows, &matrix->cols);
    
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &matrix->numTerms);
    
    printf("Enter the elements as 'row column value':\n");
    for (int i = 0; i < matrix->numTerms; i++) {
        scanf("%d %d %d", &matrix->data[i].row, &matrix->data[i].col, &matrix->data[i].value);
    }
}

// Function to display a sparse matrix
void displaySparseMatrix(SparseMatrix matrix) {
    printf("\nSparse Matrix (row, column, value):\n");
    for (int i = 0; i < matrix.numTerms; i++) {
        printf("%d\t%d\t%d\n", matrix.data[i].row, matrix.data[i].col, matrix.data[i].value);
    }
}

// Function to display the sparse matrix in normal matrix form
void displayAsNormalMatrix(SparseMatrix matrix) {
    printf("\nMatrix in normal form:\n");
    int k = 0;
    
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            if (k < matrix.numTerms && matrix.data[k].row == i && matrix.data[k].col == j) {
                printf("%d\t", matrix.data[k].value);
                k++;
            } else {
                printf("0\t");
            }
        }
        printf("\n");
    }
}

// Function to add two sparse matrices
SparseMatrix addSparseMatrices(SparseMatrix A, SparseMatrix B) {
    SparseMatrix C;
    
    // Check if dimensions match
    if (A.rows != B.rows || A.cols != B.cols) {
        printf("Error: Matrices dimensions don't match!\n");
        C.numTerms = 0;
        C.rows = 0;
        C.cols = 0;
        return C;
    }
    
    C.rows = A.rows;
    C.cols = A.cols;
    C.numTerms = 0;
    
    int i = 0, j = 0, k = 0;
    
    // Compare and add elements
    while (i < A.numTerms && j < B.numTerms) {
        // Calculate position for comparison (row-major order)
        int posA = A.data[i].row * A.cols + A.data[i].col;
        int posB = B.data[j].row * B.cols + B.data[j].col;
        
        // Element exists in A but not in same position in B
        if (posA < posB) {
            C.data[k].row = A.data[i].row;
            C.data[k].col = A.data[i].col;
            C.data[k].value = A.data[i].value;
            k++;
            i++;
        }
        // Element exists in B but not in same position in A
        else if (posA > posB) {
            C.data[k].row = B.data[j].row;
            C.data[k].col = B.data[j].col;
            C.data[k].value = B.data[j].value;
            k++;
            j++;
        }
        // Same position in both matrices, add values
        else {
            int sum = A.data[i].value + B.data[j].value;
            // Only include non-zero results
            if (sum != 0) {
                C.data[k].row = A.data[i].row;
                C.data[k].col = A.data[i].col;
                C.data[k].value = sum;
                k++;
            }
            i++;
            j++;
        }
    }
    
    // Copy remaining elements from A
    while (i < A.numTerms) {
        C.data[k].row = A.data[i].row;
        C.data[k].col = A.data[i].col;
        C.data[k].value = A.data[i].value;
        k++;
        i++;
    }
    
    // Copy remaining elements from B
    while (j < B.numTerms) {
        C.data[k].row = B.data[j].row;
        C.data[k].col = B.data[j].col;
        C.data[k].value = B.data[j].value;
        k++;
        j++;
    }
    
    C.numTerms = k;
    return C;
}

int main() {
    SparseMatrix A, B, C;
    
    printf("Enter details for first sparse matrix:\n");
    readSparseMatrix(&A);
    
    printf("\nEnter details for second sparse matrix:\n");
    readSparseMatrix(&B);
    
    // Display the input matrices
    printf("\nFirst Sparse Matrix (A):");
    displaySparseMatrix(A);
    displayAsNormalMatrix(A);
    
    printf("\nSecond Sparse Matrix (B):");
    displaySparseMatrix(B);
    displayAsNormalMatrix(B);
    
    // Add the matrices
    C = addSparseMatrices(A, B);
    
    // Display the result
    if (C.numTerms > 0) {
        printf("\nResultant Sparse Matrix (A + B):");
        displaySparseMatrix(C);
        displayAsNormalMatrix(C);
    }
    
    return 0;
}
