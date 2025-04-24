#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    
    int result = binarySearch(arr, 0, n - 1, target);
    
    if (result == -1)
        printf("Element %d is not present in the array\n", target);
    else
        printf("Element %d is present at index %d\n", target, result);
    
    target = 25;
    result = binarySearch(arr, 0, n - 1, target);
    
    if (result == -1)
        printf("Element %d is not present in the array\n", target);
    else
        printf("Element %d is present at index %d\n", target, result);
    
    return 0;
}
