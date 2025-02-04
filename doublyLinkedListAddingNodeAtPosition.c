#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};


struct node *addToPos(struct node *head, int pos ,int data);
struct node *addToEmpty(struct node *head,int data);
struct node *addNewNode(struct node *head,int data);


int main(){
    struct node *head = NULL;
    
    head = addToEmpty(head,9);
    head = addNewNode(head,99);
    head = addNewNode(head,999);
    
    head = addToPos(head,2,9999);
    
    struct node*ptr =head;
    
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
    
    return 0;
    
}

struct node *addToEmpty(struct node *head,int data){
       struct node *temp = malloc(sizeof(struct node));
       temp ->prev = NULL;
       temp ->data = data;
       temp ->next = NULL;
       
       head = temp;
       return head;
}

struct node *addNewNode(struct node *head,int data){
       struct node *temp = malloc(sizeof(struct node));
       temp ->prev = NULL;
       temp ->data = data;
       temp ->next = NULL;
       
       struct node *ptr = head;
       
       while(ptr->next!=NULL){
            ptr = ptr ->next;
       }
       ptr ->next  = temp;
       temp ->prev = ptr;
       
       return head;
}

struct node *addToPos(struct node *head, int pos ,int data){
            
            struct node *temp = malloc(sizeof(struct node));
            temp ->prev = NULL;
            temp ->data = data;
            temp ->next = NULL;
            
            struct node *ptr = head;
            struct node *ptr2 = NULL;
            while(pos!=1){
                ptr = ptr->next;
                pos--;
            }
            if(ptr->next == NULL){
                ptr ->next = temp;
                temp ->prev = ptr;
            }
            else{
                temp ->next = ptr->next;
                temp ->prev = ptr;
                ptr2 = ptr ->next;
                ptr2->prev = temp;
                ptr ->next = temp;
            }
            
            return head;
    
} 

