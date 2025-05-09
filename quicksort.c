#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // Choose the rightmost element as pivot
    int i = (low - 1);        // Index of smaller element
    
    // Put elements smaller than pivot on the left
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    // Place pivot in its final position
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Iterative QuickSort function
void quickSort(int arr[], int n) {
    // Create a simple stack of size n
    int stack[n];
    int top = -1;
    
    // Push initial values of left and right to stack
    stack[++top] = 0;     // low index
    stack[++top] = n-1;   // high index
    
    // Keep popping from stack while it's not empty
    while (top >= 0) {
        // Pop high and low
        int high = stack[top--];
        int low = stack[top--];
        
        // Get pivot position
        int pivot_index = partition(arr, low, high);
        
        // If there are elements on left side of pivot,
        // push left side to stack
        if (pivot_index - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivot_index - 1;
        }
        
        // If there are elements on right side of pivot,
        // push right side to stack
        if (pivot_index + 1 < high) {
            stack[++top] = pivot_index + 1;
            stack[++top] = high;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test the sorting
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted array: ");
    printArray(arr, n);
    
    quickSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
