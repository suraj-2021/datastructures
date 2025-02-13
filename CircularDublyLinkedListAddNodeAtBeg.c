#include<stdio.h>
#include<stdlib.h>



struct node {
       
       struct node *prev;
       int data;
       struct node *next;
};

struct node *addNode(struct node *tail, int data){
       struct node *temp = malloc(sizeof(struct node));
       temp ->next = NULL;
       temp ->data = data;
       temp->prev = NULL;
       
       if(tail == NULL){
            temp ->next = temp;
            temp->prev = temp;
            tail = temp;
            
            return tail;
          
       }
       
       struct node *ptr = tail->next;
       
       temp-> next = tail->next;
       temp->prev=tail;
       tail->next = temp;
       tail = temp;
       
       return tail;
}

struct node *addAtBeg(struct node *tail, int data){
       struct node *temp = malloc(sizeof(struct node));
       temp ->next = NULL;
       temp ->data = data;
       temp ->next = NULL;
       
       
       temp->next = tail->next;
       temp->prev = tail;
       tail ->next= temp;
       
       return tail;
}


int main(){
    struct node *tail = NULL;
    tail = addNode(tail,9);
    tail = addNode(tail,99);
    tail = addNode(tail,999);
    
    tail = addAtBeg(tail,100000);
    
    struct node *ptr = tail->next;
    
    do{
        printf("%d\n",ptr->data);
        ptr = ptr->next;
        
    }while(ptr!=tail->next);
    
    
    return 0;
    
}




