#include <stdio.h>
#include <stdlib.h>
#define max 100

// Struct to represent the elements in sparse matrix 
typedef struct element {
    int row;
    int col;
    int val; // Fixed: 'in val' to 'int val'
} element;

// Struct to represent the sparse matrix 
typedef struct sparsematrix {
    int rows;
    int cols;
    int numterms;
    element data[max];
} sparsematrix;

// Function to read sparsematrix
void readsparsematrix(sparsematrix *matrix) {
    printf("Provide the number of rows and cols in your matrix in 'rows-cols' format: ");
    scanf("%d %d", &matrix->rows, &matrix->cols);
    
    printf("How many non zero elements are there in your sparsematrix: ");
    scanf("%d", &matrix->numterms);
    
    printf("Provide the terms of sparse matrix in row-col-value format: \n");
    for (int i = 0; i < matrix->numterms; i++) { // Fixed: matix to matrix
        scanf("%d %d %d", &matrix->data[i].row, &matrix->data[i].col, &matrix->data[i].val); // Fixed: value to val
    }
} 

// Function to display the sparse matrix 
void displaysparsematrix(sparsematrix matrix) {
    printf("The sparse matrix is: \n");
    
    for (int i = 0; i < matrix.numterms; i++) {
        printf("%d %d %d\n", matrix.data[i].row, matrix.data[i].col, matrix.data[i].val); // Fixed: dat to data, value to val
    }
    printf("\n");
}

// Function to display the matrix in normal form 
void displaymatrixnormally(sparsematrix matrix) {
    int k = 0; // Fixed: missing semicolon
    
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) { // Fixed: missing semicolon and brace
            if (k < matrix.numterms && matrix.data[k].row == i && matrix.data[k].col == j) {
                printf("%d\t", matrix.data[k].val); // Fixed: value to val
                k++;
            } else {
                printf("0\t");
            }
        }
        printf("\n");
        // Removed problematic increment statements: i++ and j++
    }
}

// Function to add two sparse matrices
sparsematrix addsparsematrices(sparsematrix A, sparsematrix B) {
    sparsematrix C;
    
    if (A.rows != B.rows || A.cols != B.cols) {
        printf("The matrices are not compatible for addition!\n");
        C.numterms = 0; // Fixed: numters to numterms
        C.rows = 0;
        C.cols = 0;
        
        return C;
    }
    
    C.rows = A.rows;
    C.cols = A.cols;
    C.numterms = 0;
    
    int i = 0, j = 0, k = 0;
    
    while (i < A.numterms && j < B.numterms) { // Fixed: While to while
        // Determining the position of non zero elements in A and B 
        int posA = A.data[i].row * A.cols + A.data[i].col;
        int posB = B.data[j].row * B.cols + B.data[j].col; // Fixed: B.data[i].col to B.data[j].col
        
        // If non zero is in A but not in B
        if (posA < posB) {
            C.data[k].row = A.data[i].row;
            C.data[k].col = A.data[i].col;
            C.data[k].val = A.data[i].val; // Fixed: value to val
            
            k++;
            i++;
        } else if (posA > posB) {
            C.data[k].row = B.data[j].row;
            C.data[k].col = B.data[j].col;
            C.data[k].val = B.data[j].val; // Fixed: value to val
            
            k++;
            j++;
        } else {
            // Elements are at the same position, add them
            int sum = A.data[i].val + B.data[j].val; // Fixed: value to val
            if (sum != 0) { // Only store non-zero results
                C.data[k].row = A.data[i].row;
                C.data[k].col = A.data[i].col;
                C.data[k].val = sum; // Fixed: value to val
                k++;
            }
            i++;
            j++;
        }
    }
    
    // Copy the remaining elements from matrix A to C 
    while (i < A.numterms) { // Fixed: numters to numterms
        C.data[k].row = A.data[i].row;
        C.data[k].col = A.data[i].col;
        C.data[k].val = A.data[i].val; // Fixed: value to val
        
        k++;
        i++;
    }
    
    // Copy the remaining elements from matrix B to C 
    while (j < B.numterms) {
        C.data[k].row = B.data[j].row;
        C.data[k].col = B.data[j].col;
        C.data[k].val = B.data[j].val; // Fixed: value to val
        
        k++;
        j++;
    }
    
    C.numterms = k;
    return C; 
}

// Function to perform the multiplication of the sparse matrix 
sparsematrix multiplysparsematrices(sparsematrix A, sparsematrix B) {
    sparsematrix result;
    
    if (A.cols != B.rows) {
        printf("Matrices are incompatible for multiplication!\n");
        exit(-1);
    }
    
    // Creating temp variable to store the results
    element *temp = malloc(A.numterms * B.numterms * sizeof(element)); 
    int count = 0;
    
    for (int i = 0; i < A.numterms; i++) {
        int rowA = A.data[i].row;
        int colA = A.data[i].col;
        int valA = A.data[i].val; // Fixed: value to val
        
        for (int j = 0; j < B.numterms; j++) {
            int rowB = B.data[j].row; // Fixed: i to j
            int colB = B.data[j].col; // Fixed: i to j
            int valB = B.data[j].val; // Fixed: i to j, value to val
            
            if (colA == rowB) {
                int found = 0;
                
                for (int k = 0; k < count; k++) {
                    if (temp[k].row == rowA && temp[k].col == colB) {
                        temp[k].val += valA * valB; // Fixed: value to val
                        found = 1;
                        break; // Removed erroneous k++ that would skip elements
                    }
                }
                
                if (!found) {
                    temp[count].row = rowA; // Fixed: temp[k] to temp[count]
                    temp[count].col = colB; // Fixed: temp[k] to temp[count]
                    temp[count].val = valA * valB; // Fixed: value to val, temp[k] to temp[count]
                    count++;
                }
            }
        }
    }
    
    // Create the result matrix
    result.rows = A.rows; // Fixed: A.row to A.rows
    result.cols = B.cols;
    result.numterms = count; // Fixed: reult to result
    
    for (int i = 0; i < count; i++) {
        result.data[i] = temp[i]; // Fixed: copying the entire struct instead of just value
    }
    
    free(temp);
    return result;
}

int main() {
    sparsematrix A, B, C;
    
    // Read matrices
    readsparsematrix(&A); // Fixed: not assigning the return value
    readsparsematrix(&B); // Fixed: not assigning the return value
    
    // Add matrices
    C = addsparsematrices(A, B);
    
    // Display matrices
    printf("First sparse matrix (A):\n");
    displaysparsematrix(A);
    
    printf("Second sparse matrix (B):\n");
    displaysparsematrix(B);
    
    printf("Result of addition (C = A + B):\n");
    displaysparsematrix(C);
    
    // Optional: Display in normal form
    printf("Matrix A in normal form:\n");
    displaymatrixnormally(A);
    
    printf("Matrix B in normal form:\n");
    displaymatrixnormally(B);
    
    printf("Result matrix C in normal form:\n");
    displaymatrixnormally(C);
    
    // Multiply matrices
    printf("\nPerforming multiplication...\n");
    sparsematrix D = multiplysparsematrices(A, B);
    printf("Result of multiplication (D = A * B):\n");
    displaysparsematrix(D);
    printf("Result matrix D in normal form:\n");
    displaymatrixnormally(D);
    
    return 0;
}
