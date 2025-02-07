#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};


struct node *addNode(struct node*head,int data){
       struct node *temp = malloc(sizeof(struct node));
       temp ->data = data;
       temp ->prev = NULL;
       temp->next = NULL;
       
       if(head == NULL){
           head = temp;
           return head;
       }
       else{
           struct node *ptr = head;
           while(ptr->next != NULL){
               ptr = ptr->next;
           }
           ptr ->next = temp;
           temp->prev = ptr;
           
           return head;
           
       }
}


struct node *reverse(struct node *head){
        struct node *ptr1 = head;
        struct node *ptr2 = ptr1->next;
        
        ptr1->next = NULL;
        ptr1->prev = ptr2;
        
        
        while(ptr2!=NULL){
            
            ptr2->prev = ptr2->next;
            ptr2 ->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->prev;
        }
        
        head = ptr1;
        return head;
}


int main(){
    struct node *head = NULL;
    head = addNode(head,9);
    head = addNode(head,99);
    head = addNode(head,999);
    head = addNode(head,9999);
    
    head = reverse(head);
    
    struct node *ptr = head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
    
    return 0;
}
