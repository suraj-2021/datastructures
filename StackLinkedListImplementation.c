#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
}*top = NULL;



int isEmpty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}


void push(int data){
     struct node *newNode = malloc(sizeof(struct node));
     if(newNode == NULL){
         printf("STACK OVERFLOW!");
         exit(1);
     }
     newNode->data = data;
     newNode->link = NULL;
     
     newNode->link =top;
     top = newNode;
}

int pop(){
    int value;
    struct node *ptr;
    if(isEmpty()){
        printf("STACK UNDERFLOW");
        exit(1);
    }
    ptr = top;
    value = ptr->data;
    top = top->link;
    free(ptr);
    ptr = NULL;
    return value;
}

int peek(){
    if(isEmpty()){
        printf("STACK UNDERFLOW!");
        exit(1);
    }
    return top->data;
}


void print(){
    struct node *ptr = top;
    if(isEmpty()){
        printf("STACK UNDERFLOW");
        exit(1);
    }
    
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->link;
    }
}
int main(){
    int choice, data;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print\n");
        printf("5. Quit\n");
        
        printf("Please Enter your Choice: ");
        scanf("%d",&choice);
        
        switch(choice){
        case 1:
             printf("Enter value to push: ");
             scanf("%d",&data);
             push(data);
             break;
        
        case 2:
             printf("The Popped value is : %d\n",pop());
             break;
        
        case 3: 
            printf("The topmost value in the Stack is : %d\n",peek());
            break;
        case 4: 
             print();
             break;
        
        case 5:
             printf("Thanks for using our service!");
             exit(1);
        default:
            printf("Invalid choice, Try Again!");
            break;
        }
    }
    return 0;
}
