#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node*link;
};
struct node*add_beg(struct node*head,int data);
int main(){
    struct node *head = malloc(sizeof(struct node));
    head ->data=9;
    head->link =NULL;
    
    struct node *ptr = malloc(sizeof(struct node));
    ptr ->data = 90;
    ptr->link = NULL;
    
    head->link = ptr;
    
    head = add_beg(head,108);
    ptr=head;
    while(ptr!=NULL){
        printf("Data: %d\n",ptr->data);
        ptr = ptr->link;
    }
    return 0;
}

struct node*add_beg(struct node*head,int data){
    struct node*ptr = malloc(sizeof(struct node));
    ptr ->data = data;
    ptr -> link = head;
    head = ptr;
    return head;
}
