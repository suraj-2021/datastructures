#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node*link;
};

void add_beg(struct node **head,int data);

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 9;
    head->link=NULL;
    
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = 90;
    ptr->link = NULL;
    
    head->link = ptr;
    
    add_beg(&head,108);
    
    ptr=head;
    
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr= ptr->link;
    }
    
    return 0;
}

void add_beg(struct node **head,int data){
     struct node *temp = malloc(sizeof(struct node));
     temp->data=data;
     temp->link = *head;
     
     *head  = temp;
}
