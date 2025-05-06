#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int mat1[10][10], mat2[10][10];
    int sum[10][10];
    int product[10][10];

public:
    // Constructor to set matrix size
    Matrix(int r, int c) {
        rows = r;
        cols = c;
    }

    // Method to input elements of both matrices
    void inputMatrices() {
        cout << "Enter elements of first matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat1[i][j];
            }
        }

        cout << "Enter elements of second matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat2[i][j];
            }
        }
    }

    // Method to add matrices
    void addMatrices() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
    }

    // Method to display the sum matrix
    void displaySum() {
        cout << "Sum of the two matrices:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << sum[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Method to multiply matrices
    // Note: For multiplication, number of columns in mat1 must equal number of rows in mat2
    // Here, we assume square matrices of size rows x cols for simplicity
    void multiplyMatrices() {
        // Initialize product matrix to zero
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                product[i][j] = 0;
            }
        }

        // Multiply mat1 and mat2
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < cols; k++) {
                    product[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
    }

    // Method to display the product matrix
    void displayProduct() {
        cout << "Product of the two matrices:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << product[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int r, c;
    cout << "Enter number of rows and columns (max 10, square matrices assumed): ";
    cin >> r >> c;

    Matrix matrix(r, c);

    matrix.inputMatrices();

    matrix.addMatrices();
    matrix.displaySum();

    matrix.multiplyMatrices();
    matrix.displayProduct();

    return 0;
}
