#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100  // Maximum number of elements in our list

// Structure representing our array-based linked list
typedef struct {
    int data[MAX_SIZE];       // Array to store data values
    int next[MAX_SIZE];       // Array to store "next" indices
    int head;                 // Index of the first element
    int free_head;            // Index of the first free slot
    int size;                 // Current number of elements in the list
} ArrayList;

// Initialize the list
void initList(ArrayList* list) {
    list->head = -1;  // Empty list has no head
    list->size = 0;
    
    // Initialize the free list (all slots are initially free)
    list->free_head = 0;
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        list->next[i] = i + 1;  // Each free slot points to the next free slot
    }
    list->next[MAX_SIZE - 1] = -1;  // Last slot has no next
}

// Check if the list is empty
bool isEmpty(ArrayList* list) {
    return list->head == -1;
}

// Check if the list is full
bool isFull(ArrayList* list) {
    return list->size == MAX_SIZE;
}

// Insert a value at the beginning of the list
bool insertAtBeginning(ArrayList* list, int value) {
    if (isFull(list)) {
        printf("List is full. Cannot insert.\n");
        return false;
    }
    
    // Get a free position
    int pos = list->free_head;
    list->free_head = list->next[pos];
    
    // Store data and update links
    list->data[pos] = value;
    list->next[pos] = list->head;
    list->head = pos;
    list->size++;
    
    return true;
}

// Insert a value at the end of the list
bool insertAtEnd(ArrayList* list, int value) {
    if (isFull(list)) {
        printf("List is full. Cannot insert.\n");
        return false;
    }
    
    // Get a free position
    int pos = list->free_head;
    list->free_head = list->next[pos];
    list->data[pos] = value;
    list->next[pos] = -1;  // New node points to nothing
    
    // If list was empty, update head
    if (isEmpty(list)) {
        list->head = pos;
    } else {
        // Find the last node
        int current = list->head;
        while (list->next[current] != -1) {
            current = list->next[current];
        }
        // Update the last node to point to the new node
        list->next[current] = pos;
    }
    
    list->size++;
    return true;
}

// Delete the first element
bool deleteFromBeginning(ArrayList* list) {
    if (isEmpty(list)) {
        printf("List is empty. Cannot delete.\n");
        return false;
    }
    
    // Get the position of the head
    int pos = list->head;
    
    // Update head to the next element
    list->head = list->next[pos];
    
    // Return the position to the free list
    list->next[pos] = list->free_head;
    list->free_head = pos;
    
    list->size--;
    return true;
}

// Search for a value in the list
int search(ArrayList* list, int value) {
    if (isEmpty(list)) {
        return -1;  // List is empty
    }
    
    int current = list->head;
    int position = 0;
    
    while (current != -1) {
        if (list->data[current] == value) {
            return position;  // Found at this position
        }
        current = list->next[current];
        position++;
    }
    
    return -1;  // Not found
}

// Display the list contents
void displayList(ArrayList* list) {
    if (isEmpty(list)) {
        printf("List is empty.\n");
        return;
    }
    
    printf("List contents: ");
    int current = list->head;
    
    while (current != -1) {
        printf("%d ", list->data[current]);
        current = list->next[current];
    }
    printf("\n");
}

// Main function to demonstrate usage
int main() {
    ArrayList list;
    initList(&list);
    
    // Insert some elements
    insertAtBeginning(&list, 10);
    insertAtBeginning(&list, 20);
    insertAtEnd(&list, 30);
    
    // Display the list
    displayList(&list);  // Should display: 20 10 30
    
    // Search for a value
    int pos = search(&list, 10);
    if (pos != -1) {
        printf("Value 10 found at position %d\n", pos);
    } else {
        printf("Value 10 not found\n");
    }
    
    // Delete from beginning
    deleteFromBeginning(&list);
    displayList(&list);  // Should display: 10 30
    
    return 0;
}
