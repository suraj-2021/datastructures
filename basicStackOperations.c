#include<stdio.h>
#include<stdlib.h>
#define MAX 4 

int stack_arr[MAX];
int top = -1;


int isFull(){
    if(top==MAX-1){
        return 1;
    }
    return 0;
}


int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

void push(int data){
    if(isFull()){
        printf("Stack Overflow");
        return;
    }
    top +=1;
    stack_arr[top] = data;
}

int pop(){
    int value;
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    value = stack_arr[top];
    top -= 1;
    
    return value;
}

int peek(){
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    
    return stack_arr[top];
}

void print(){
    for(int i=top;i>=0;i--){
        printf("%d\n",stack_arr[i]);
    }
}

int main(){
    int choice,data;
    
    while(1){
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print the Elements in the Stack\n");
        printf("5. Quit\n");
        
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        
        switch(choice){
        case 1: 
            printf("Provide value to be pushed: ");
            scanf("%d",&data);
            
            push(data);
            break;
        case 2: 
           data = pop();
            
           printf("The data that you peeked is : %d\n",data);
            break;
            
        case 3: 
            data = peek();
            printf("The data that you popped is : %d\n",data);
            break;
                    
        case 4: 
            print();
            break;
            
        case 5:
            exit(1);
            
        default:
           printf("Invalid Input, Try again!");
        }
        
    }
    return 0;
}
