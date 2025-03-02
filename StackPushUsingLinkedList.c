
#include<stdio.h>
#include<stdlib.h>

struct node{
     int data;
     struct node *link;
} *top = NULL;


void push(int data){
    struct node *newNode = malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("STACK OVERFLOW");
        exit(1);
    }
    newNode->data = data;
    newNode ->link = NULL;
    
    newNode ->link = top;
    top = newNode;
} 

void print(){
    struct node *ptr = top;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->link;
    }
    
}


int main(){
    int choice,data;
    
    while(1){
        printf("1. Push\n");
        printf("2. Print\n");
        printf("3. Exit\n");
        printf("Provide your response: ");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("Provide Value to Push: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                 print();
                 break;
            case 3:
                exit(1);
            
            default:
                printf("Provide Valid Response, Try Again!");
                break;
        }
    }
    
  return 0;  
}

