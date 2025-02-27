#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, int value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    } else {
        printf("Stack is full. Cannot push %d.\n", value);
    }
}

int pop(Stack *stack) {
    if (stack->top >= 0) {
        int value = stack->data[stack->top--];
        printf("Popped %d from the stack.\n", value);
        return value;
    }
    printf("Stack is empty. Cannot pop.\n");
    return -1; // Return a sentinel value to indicate failure
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    pop(&stack);
    pop(&stack);

    return 0;
}
