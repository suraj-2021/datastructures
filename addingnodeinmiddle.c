#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *link;
};

void add_node(struct node**head,int data);
void add_middle(struct node*head,int data,int pos);
int main(){
    struct node *head = NULL;
    
    add_node(&head,90);
    add_node(&head,9);
    add_node(&head,99);
    int data=999;
    int pos = 3;
    add_middle(head,data,pos);
    
    struct node*ptr = head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr= ptr->link;
    }
    return 0;
    
    
}

void add_node(struct node**head,int data){
    struct node *temp = malloc(sizeof(struct node));
           temp ->data=data;
           temp ->link = NULL;
    
    if(*head==NULL){
        *head = temp;
    }
    else{
        struct node*ptr= *head;
        while(ptr->link!=NULL){
             ptr = ptr->link;   
        }
        
        ptr->link = temp;
    }
    
}

void add_middle(struct node*head,int data,int pos){
        struct node *temp = malloc(sizeof(struct node));
               temp ->data= data;
               temp->link= NULL;
              
        struct node *ptr = head;
        
        for(int i=0;i<pos-2;i++){
            ptr = ptr->link;
        }
        
        temp->link = ptr->link;
        ptr->link = temp;
        
}    
