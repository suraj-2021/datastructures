#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

// Node structure for the Red-Black Tree
typedef struct Node {
    int data;
    Color color;
    struct Node *left, *right, *parent;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are initially red
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

// Function for left rotation
void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
}

// Function for right rotation
void rightRotate(Node** root, Node* x) {
    Node* y = x->left;
    x->left = y->right;

    if (y->right != NULL) {
        y->right->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }

    y->right = x;
    x->parent = y;
}

// Fix violations after insertion
void fixInsert(Node** root, Node* z) {
    while (z != *root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* uncle = z->parent->parent->right;

            if (uncle != NULL && uncle->color == RED) { // Case 1: Uncle is red
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent; // Move up the tree
            } else { // Case 2 and 3: Uncle is black
                if (z == z->parent->right) { // Case 2: Triangle configuration
                    z = z->parent;
                    leftRotate(root, z);
                }
                // Case 3: Line configuration
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(root, z->parent->parent);
            }
        } else { // Symmetric cases for right child
            Node* uncle = z->parent->parent->left;

            if (uncle != NULL && uncle->color == RED) { // Case 1: Uncle is red
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent; // Move up the tree
            } else { // Case 2 and 3: Uncle is black
                if (z == z->parent->left) { // Case 2: Triangle configuration
                    z = z->parent;
                    rightRotate(root, z);
                }
                // Case 3: Line configuration
                z->parent->color = BLACK;
                z->parent->parent -> color=RED
