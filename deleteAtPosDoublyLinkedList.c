#include<stdio.h>
#include<stdlib.h>


struct node {
    struct node *prev;
    int data;
    struct node *next;
};


struct node *addNode(struct node *head, int data){
       struct node *temp = malloc(sizeof(struct node));
       temp ->prev = NULL;
       temp ->data = data;
       temp ->next = NULL;
       
       if (head==NULL){
           head = temp;
           return head;
       }
       else{
           struct node *ptr = head;
           while(ptr->next !=NULL){
               ptr = ptr->next;
            }
            
            ptr->next = temp;
            temp->prev = ptr;
            
            return head;
       }
       
}

struct node *delAtPos(struct node *head,int pos){
       
       struct node *ptr = head;
       struct node *temp =NULL;
       int i=1;
       
       while(i<pos){
           ptr =ptr->next;
           pos--;
       }
       
       ptr->prev->next = ptr->next;
       ptr->next->prev = ptr->prev;
       free(ptr);
       ptr = NULL;
       
       return head;
}


int main(){
    struct node *head = NULL;
    
    head = addNode(head,9);
    head = addNode(head,99);
    head = addNode(head,999);
    head = addNode(head,9999);
    
    head = delAtPos(head,3);
    
    struct node *ptr = head;
    
    while(ptr!= NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
        }
        
        return 0;
}
