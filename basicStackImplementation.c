#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Define the stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1; // Set top to -1, meaning the stack is initially empty
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* s) {
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack* s, int data) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d.\n", data);
    } else {
        s->items[++s->top] = data;
        printf("Pushed %d onto the stack.\n", data);
    }
}

// Function to pop an element from the stack
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return a sentinel value to indicate error
    } else {
        printf("Popped %d from the stack.\n", s->items[s->top]);
        return s->items[s->top--];
    }
}

// Function to peek at the top element of the stack
int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return a sentinel value to indicate error
    } else {
        printf("Top element is %d.\n", s->items[s->top]);
        return s->items[s->top];
    }
}

// Function to print the stack elements
void printStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    initStack(&stack);

    // Example usage
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStack(&stack);

    peek(&stack);

    pop(&stack);

    printStack(&stack);

    return 0;
}
