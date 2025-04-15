#include <stdio.h>
#include <stdlib.h>

// Function to sort a single row using bubble sort
void sortRow(int *row, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (row[j] > row[j + 1]) {
                // Swap elements
                temp = row[j];
                row[j] = row[j + 1];
                row[j + 1] = temp;
            }
        }
    }
}

// Function to sort all rows of a matrix
void sortMatrixRowWise(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        sortRow(matrix[i], cols);
    }
}

// Function to print matrix
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to allocate memory for matrix
int** allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free allocated memory
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows, cols;
    
    // Get matrix dimensions
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    
    // Allocate memory for matrix
    int **matrix = allocateMatrix(rows, cols);
    
    // Input matrix elements
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Print original matrix
    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, rows, cols);
    
    // Sort matrix row-wise
    sortMatrixRowWise(matrix, rows, cols);
    
    // Print sorted matrix
    printf("\nMatrix after row-wise sorting:\n");
    printMatrix(matrix, rows, cols);
    
    // Free allocated memory
    freeMatrix(matrix, rows);
    
    return 0;
}
