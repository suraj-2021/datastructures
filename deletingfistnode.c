#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node* del_first(struct node *head);

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data=9;
    head->link =NULL;
    
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 90;
    ptr ->link = NULL;
    
    head->link = ptr;
    
    ptr= malloc(sizeof(struct node));
    ptr ->data=99;
    ptr->link = NULL;
    
    head->link->link = ptr;
    
    
    head =  del_first(head);
    ptr = head;

    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
    
    
    return 0;
}

struct node* del_first(struct node *head){
        if(head == NULL){
            printf("The head is already NULL!");
            
        }
        else{
            struct node *ptr = head;
            head = head->link;
            free(ptr);
            
            }
            
        return head;
}

