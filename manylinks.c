#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main(){
    struct node *head = malloc(sizeof(struct node));
    head ->data=45;
    head ->link= NULL;
    
    struct node *current = malloc(sizeof(struct node));
    current ->data = 90;
    current ->link = NULL;
    
    head ->link = current;
    
    current = malloc(sizeof(struct node));
    current ->data=50;
    current ->link = NULL;
    
    head ->link->link = current;
    
    current = malloc(sizeof(struct node));
    current ->data = 100;
    current ->link = NULL;
    
    head ->link->link->link = current;
    
    
    printf("Third Node's value is : %d\n",head->link->link->link->data);
    
    return 0;
}
