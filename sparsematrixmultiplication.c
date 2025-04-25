#include <stdio.h>

#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} Term;

void printMatrix(Term a[], int size) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    }
}

void sparseAdd(Term a[], Term b[], Term c[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("Matrices have different dimensions. Cannot add.\n");
        c[0].row = c[0].col = c[0].value = 0;
        return;
    }

    c[0].row = a[0].row;
    c[0].col = a[0].col;
    
    int aPos = 1, bPos = 1, cPos = 1;
    
    while (aPos <= a[0].value && bPos <= b[0].value) {
        if (a[aPos].row < b[bPos].row || 
            (a[aPos].row == b[bPos].row && a[aPos].col < b[bPos].col)) {
            c[cPos] = a[aPos];
            aPos++;
            cPos++;
        } else if (a[aPos].row > b[bPos].row || 
                  (a[aPos].row == b[bPos].row && a[aPos].col > b[bPos].col)) {
            c[cPos] = b[bPos];
            bPos++;
            cPos++;
        } else {
            int sum = a[aPos].value + b[bPos].value;
            if (sum != 0) {
                c[cPos].row = a[aPos].row;
                c[cPos].col = a[aPos].col;
                c[cPos].value = sum;
                cPos++;
            }
            aPos++;
            bPos++;
        }
    }
    
    while (aPos <= a[0].value) {
        c[cPos] = a[aPos];
        aPos++;
        cPos++;
    }
    
    while (bPos <= b[0].value) {
        c[cPos] = b[bPos];
        bPos++;
        cPos++;
    }
    
    c[0].value = cPos - 1;
}

void sparseMultiply(Term a[], Term b[], Term d[]) {
    if (a[0].col != b[0].row) {
        printf("Matrices cannot be multiplied: invalid dimensions.\n");
        d[0].row = d[0].col = d[0].value = 0;
        return;
    }

    d[0].row = a[0].row;
    d[0].col = b[0].col;
    d[0].value = 0;

    int dPos = 1;
    
    for (int aPos = 1; aPos <= a[0].value; ) {
        int currentARow = a[aPos].row;
        
        for (int bPos = 1; bPos <= b[0].value; ) {
            int currentBCol = b[bPos].col;
            
            int sum = 0;
            int tempAPos = aPos;
            int tempBPos = bPos;
            
            while (tempAPos <= a[0].value && a[tempAPos].row == currentARow &&
                   tempBPos <= b[0].value && b[tempBPos].col == currentBCol) {
                if (a[tempAPos].col == b[tempBPos].row) {
                    sum += a[tempAPos].value * b[tempBPos].value;
                    tempAPos++;
                    tempBPos++;
                } 
                else if (a[tempAPos].col < b[tempBPos].row) {
                    tempAPos++;
                }
                else {
                    tempBPos++;
                }
            }
            
            if (sum != 0) {
                if (dPos >= MAX_TERMS) {
                    printf("Result matrix exceeds maximum capacity.\n");
                    return;
                }
                d[dPos].row = currentARow;
                d[dPos].col = currentBCol;
                d[dPos].value = sum;
                dPos++;
            }
            
            while (bPos <= b[0].value && b[bPos].col == currentBCol) {
                bPos++;
            }
        }
        
        while (aPos <= a[0].value && a[aPos].row == currentARow) {
            aPos++;
        }
    }
    
    d[0].value = dPos - 1;
}

int main() {
    Term a[MAX_TERMS], b[MAX_TERMS], c[MAX_TERMS], d[MAX_TERMS];
    
    a[0].row = 3; a[0].col = 3; a[0].value = 3;
    a[1].row = 0; a[1].col = 0; a[1].value = 1;
    a[2].row = 1; a[2].col = 1; a[2].value = 2;
    a[3].row = 2; a[3].col = 2; a[3].value = 3;
    
    b[0].row = 3; b[0].col = 3; b[0].value = 3;
    b[1].row = 0; b[1].col = 0; b[1].value = 4;
    b[2].row = 1; b[2].col = 1; b[2].value = 5;
    b[3].row = 2; b[3].col = 0; b[3].value = 6;
    
    printf("Matrix A:\n");
    printMatrix(a, a[0].value + 1);
    
    printf("\nMatrix B:\n");
    printMatrix(b, b[0].value + 1);
    
    sparseAdd(a, b, c);
    
    printf("\nResult Matrix C (A + B):\n");
    printMatrix(c, c[0].value + 1);
    
    sparseMultiply(a, b, d);
    
    printf("\nResult Matrix D (A * B):\n");
    printMatrix(d, d[0].value + 1);
    
    return 0;
}
