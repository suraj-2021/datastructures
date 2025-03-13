#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

int space(char c) { /* unchanged */ }
int isEmpty() { /* unchanged */ }
void push(int c) { /* unchanged */ }
int pop() { /* unchanged */ }
int precedence(char symbol) { /* unchanged */ }

void inToPost() {
    int i, j = 0;
    char symbol, next;
    
    // Remove newline from infix
    infix[strcspn(infix, "\n")] = '\0';
    
    for(i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        if(!space(symbol)) {
            switch(symbol) {
                case '(': 
                    push(symbol);
                    break;
                case ')':
                    while((next = pop()) != '(') {
                        postfix[j++] = next;
                    }
                    break;
                case '^': case '*': case '/': case '+': case '-':
                    while(!isEmpty() && precedence(stack[top]) >= precedence(symbol)) {
                        postfix[j++] = pop();
                    }
                    push(symbol);
                    break;
                default:
                    postfix[j++] = symbol;
            }
        }
    }
    while(!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int post_eval() {
    int i, val_stack[MAX], val_top = -1;
    char symbol;
    
    for(i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];
        if(symbol >= '0' && symbol <= '9') {
            val_stack[++val_top] = symbol - '0';
        } else {
            int a = val_stack[val_top--];
            int b = val_stack[val_top--];
            switch(symbol) {
                case '+': val_stack[++val_top] = b + a; break;
                case '-': val_stack[++val_top] = b - a; break;
                case '*': val_stack[++val_top] = b * a; break;
                case '/': val_stack[++val_top] = b / a; break;
                case '^': val_stack[++val_top] = pow(b, a); break;
            }
        }
    }
    return val_stack[val_top];
}

int main() {
    printf("Provide Infix Expression: ");
    fgets(infix, sizeof(infix), stdin);
    
    inToPost();
    int value = post_eval();
    
    printf("Postfix: %s\n", postfix);
    printf("Result: %d\n", value);
    return 0;
}
