#include <stdio.h>
#define MAX_TERMS 100 // Maximum terms per polynomial

// Structure
struct Term {
    float coeff; // Coefficient (e.g., 3 in 3x^2)
    int exp;     // Exponent (e.g., 2 in 3x^2)
};


//Take inputs
void inputPolynomial(struct Term poly[], int *size) {
    *size = 0; // Initialize term count
    printf("Enter terms (coefficient exponent). End with [0 0]:\n");
    while (*size < MAX_TERMS) {
        float coeff;
        int exp;
        scanf("%f %d", &coeff, &exp);
        if (coeff == 0 && exp == 0) break; // Terminate input
        poly[*size].coeff = coeff;
        poly[*size].exp = exp;
        (*size)++;
    }
}

//Sort Inputs
void sortPolynomial(struct Term poly[], int size) {
    // Bubble sort (descending order by exponent)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (poly[j].exp < poly[j + 1].exp) {
                // Swap terms
                struct Term temp = poly[j];
                poly[j] = poly[j + 1];
                poly[j + 1] = temp;
            }
        }
    }
} 

//Add like terms
void combineLikeTerms(struct Term poly[], int *size) {
    if (*size == 0) return;
    struct Term new_poly[MAX_TERMS];
    int new_index = 0;
    new_poly[0] = poly[0];
    for (int i = 1; i < *size; i++) {
        if (poly[i].exp == new_poly[new_index].exp) {
            new_poly[new_index].coeff += poly[i].coeff; // Merge coefficients
        } else {
            new_index++;
            new_poly[new_index] = poly[i];
        }
    }
    // Update the original array and size
    for (int i = 0; i <= new_index; i++) poly[i] = new_poly[i];
    *size = new_index + 1;
} 

//Add polynomials
void addPolynomials(
    struct Term poly1[], int size1, // First polynomial
    struct Term poly2[], int size2, // Second polynomial
    struct Term result[], int *result_size // Result storage
) {
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        // Compare exponents and merge
        if (poly1[i].exp > poly2[j].exp) {
            result[k++] = poly1[i++];
        } else if (poly2[j].exp > poly1[i].exp) {
            result[k++] = poly2[j++];
        } else {
            // Add coefficients if exponents match
            float sum = poly1[i].coeff + poly2[j].coeff;
            if (sum != 0) {
                result[k].coeff = sum;
                result[k].exp = poly1[i].exp;
                k++;
            }
            i++; j++;
        }
    }
    // Add remaining terms from poly1 or poly2
    while (i < size1) result[k++] = poly1[i++];
    while (j < size2) result[k++] = poly2[j++];
    *result_size = k;
}

//Display Polynomials
void displayPolynomial(struct Term poly[], int size) {
    if (size == 0) {
        printf("0\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        // Handle signs and formatting
        if (i > 0) {
            if (poly[i].coeff > 0) printf(" + ");
            else {
                printf(" - ");
                poly[i].coeff = -poly[i].coeff; // Display absolute value
            }
        }
        // Handle term formatting
        if (poly[i].exp == 0) printf("%.2f", poly[i].coeff);
        else if (poly[i].exp == 1) printf("%.2fx", poly[i].coeff);
        else printf("%.2fx^%d", poly[i].coeff, poly[i].exp);
    }
    printf("\n");
}

int main() {
    struct Term poly1[MAX_TERMS], poly2[MAX_TERMS], result[MAX_TERMS];
    int size1, size2, result_size;

    // Input and process first polynomial
    printf("Enter first polynomial:\n");
    inputPolynomial(poly1, &size1);
    sortPolynomial(poly1, size1);
    combineLikeTerms(poly1, &size1);

    // Input and process second polynomial
    printf("Enter second polynomial:\n");
    inputPolynomial(poly2, &size2);
    sortPolynomial(poly2, size2);
    combineLikeTerms(poly2, &size2);

    // Add polynomials and display results
    addPolynomials(poly1, size1, poly2, size2, result, &result_size);
    printf("\nFirst polynomial: ");
    displayPolynomial(poly1, size1);
    printf("Second polynomial: ");
    displayPolynomial(poly2, size2);
    printf("Sum: ");
    displayPolynomial(result, result_size);

    return 0;
} 

