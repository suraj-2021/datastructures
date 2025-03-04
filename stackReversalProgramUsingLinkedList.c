#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

int isEmpty(struct node *top){
    if(top==NULL){
        return 1;
    }
    return 0;
}

void push(struct node**top,int data){
    struct node *newNode=malloc(sizeof(struct node));
    if(newNode==NULL){
        printf("Stack Overflow!");
        exit(1);
    }
    
    newNode->data = data;
    newNode->link = *top;
    *top = newNode;
}

int pop(struct node**top){
    int value;
    struct node *ptr;
    if(isEmpty(*top)){
        printf("Stack Underflow!");
        exit(1);
    }
    ptr = *top;
    value = ptr->data;
    *top = ptr->link;
    free(ptr); // Free the memory
    return value;
}

void reverse(struct node**top){
    struct node *top1=NULL;
    while(*top!=NULL){
        push(&top1,pop(top));    
    }
    *top = top1; // Assign the reversed stack back
}

void print(struct node **top){
    struct node *ptr = *top; // Corrected typo
    while(ptr !=NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->link;
    }
    printf("\n"); // Added newline for better output
}

int main(){
    struct node *top = NULL;
    int choice,data;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Reverse\n");
        printf("4. Print\n");
        printf("5. Exit\n");
        printf("Enter your Choice!: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                  printf("Enter Value to Push to the Stack: ");
                  scanf("%d",&data);
                  push(&top,data);
                  break;
            case 2:
                  if(!isEmpty(top)) {
                      printf("Popped Value: %d\n", pop(&top));
                  }
                  break;
            case 3:
                 reverse(&top);
                 printf("The stack is Reversed!\n");
                 break;
            case 4:
                  printf("The Stack is: \n");
                  print(&top);
                  break;
            
            case 5:
                  exit(1);
                  
            default:
                printf("Invalid Response, Try Again!\n");
        }
    }
    return 0;
}
