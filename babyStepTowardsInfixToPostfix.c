#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char stack[MAX], infix[MAX], postfix[MAX];
int top = -1;
void inToPos();
void print();
int main(){
    printf("Provide infix expression: ");
    fgets(infix,sizeof(infix),stdin);
    
    inToPos();
    print();
    return 0;
}


void push(char ch){
     
     if(top == MAX-1){
        printf("STACK OVERFLOW");
        exit(1);
     }
     
     top = top+1;
     
     stack[top] = ch;
}


char pop(){
    if(top == -1){
        printf("STACK UNDERFLOW");
        exit(1);
    }
    
    char value;
    value = stack[top];
    top = top-1;
    
    return value;
    
}


void inToPos(){
    int i,j=0;
    char symbol, next;
    for(i=0;i<strlen(infix);i++){
        symbol = infix[i];
        
        switch(symbol){
            
            case '(':
                push(symbol);
                break;
            
            case ')':
                while(next = pop() != '('){
                    postfix[j++] = symbol;
                }
            
            default:
                postfix[j++] = symbol;
        }
    }
}

void print(){
    for(int i=0;i<strlen(postfix);i++){
        printf("%c\t",postfix[i]);
    }
}
