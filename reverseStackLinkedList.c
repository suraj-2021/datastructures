#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Define the structure for a stack
typedef struct Stack {
    StackNode* top;
    int size;
} Stack;

// Function to create a new stack node
StackNode* createStackNode(int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new stack
Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (!newStack) {
        printf("Memory error\n");
        return NULL;
    }
    newStack->top = NULL;
    newStack->size = 0;
    return newStack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    StackNode* newNode = createStackNode(data);
    if (stack->top) {
        newNode->next = stack->top;
    }
    stack->top = newNode;
    stack->size++;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1; // Return an error value
    }
    int data = stack->top->data;
    StackNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return data;
}

// Function to get the top element of the stack
int top(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1; // Return an error value
    }
    return stack->top->data;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Recursive function to insert an element at the bottom of the stack
void insertAtBottom(Stack* stack, int data) {
    if (isEmpty(stack)) {
        push(stack, data);
    } else {
        int topItem = pop(stack);
        insertAtBottom(stack, data);
        push(stack, topItem);
    }
}

// Recursive function to reverse the stack
void reverseStack(Stack* stack) {
    if (!isEmpty(stack)) {
        int topItem = pop(stack);
        reverseStack(stack);
        insertAtBottom(stack, topItem);
    }
}

// Function to print the stack
void printStack(Stack* stack) {
    StackNode* current = stack->top;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Stack* stack = createStack();

    // Push elements onto the stack
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    printf("Original Stack: ");
    printStack(stack);

    // Reverse the stack
    reverseStack(stack);

    printf("Reversed Stack: ");
    printStack(stack);

    return 0;
}
