#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack_arr[MAX];
int top = -1;

int isFull(){
    if(top == MAX-1){
        return 1; 
    }
    
    return 0;
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    
    return 0;
    
}

void push(int data){
     if(isFull()){
        printf("STACK OVERFLOW");
        return;
     }
     top +=1;
     stack_arr[top] = data;
}

int pop(){
    if(isEmpty()){
        printf("STACK UNDERFLOW");
        return -1;
    }
    int num = stack_arr[top];
    top = top-1;
    return num;
}

void decimal(int num){
    while(num!=0){
        if(isFull()){
            printf("STACK OVERFLOW");
            return;
        }
        push(num%2);
        num = num/2; 
    }
}

void print(){
     if(isEmpty()){
         printf("STACK UNDERFLOW");
         return;
     }
    
     while(!isEmpty()){
        printf("%d",pop());
     }
}

int main(){
    int num;
    printf("Provide number you want to find Binary value of: ");
    scanf("%d",&num);
    
    decimal(num);
    print();
    
    return 0;
}
