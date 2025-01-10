#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;          // Data field
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
