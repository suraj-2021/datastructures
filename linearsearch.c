#include <stdio.h>
#include <stdbool.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    
    return -1;
}

bool linearSearchBoolean(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    
    return false;
}

void printArray(int arr[], int size) {
    printf("Array: [");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i < size - 1) ? ", " : "");
    }
    printf("]\n");
}

int main() {
    int arr[] = {10, 25, 30, 40, 55, 60, 75, 80};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target1 = 55;
    int target2 = 35;

    printArray(arr, size);

    int indexFound = linearSearch(arr, size, target1);
    if (indexFound != -1) {
        printf("Target %d found at index %d\n", target1, indexFound);
    } else {
        printf("Target %d not found in the array\n", target1);
    }

    indexFound = linearSearch(arr, size, target2);
    if (indexFound != -1) {
        printf("Target %d found at index %d\n", target2, indexFound);
    } else {
        printf("Target %d not found in the array\n", target2);
    }

    bool isPresent = linearSearchBoolean(arr, size, target1);
    printf("Is %d present? %s\n", target1, isPresent ? "Yes" : "No");

    return 0;
}
