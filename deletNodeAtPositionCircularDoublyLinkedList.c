#include<stdio.h>
#include<stdlib.h>


struct node {
    struct node *prev;
    int data;
    struct node *next;
};


struct node *addNode(struct node*tail,int data){
    
    struct node *temp = malloc(sizeof(struct node));
    temp ->next = NULL;
    temp->data = data;
    temp ->prev = NULL;
    
    if(tail == NULL){
        temp ->next = temp;
        temp->prev= temp;
        tail = temp;
        return tail;
    }
    else{
        temp->next = tail->next;
        temp->prev = tail;
        tail->next->prev = temp;
        tail->next = temp;
        tail = temp;
        
        return tail;
        
    }
}


struct node *delAtPos(struct node *tail,int pos){
       int i=1;
       struct node *ptr = tail->next;
       
       while(i<pos){
           ptr = ptr->next;
           pos--;
       }
       
       
       ptr->prev->next = ptr->next;
       ptr->next->prev = ptr->prev;
   
       free(ptr);
       ptr = NULL;
    
       return tail;
}


int main(){
    struct node *tail = NULL;
    tail = addNode(tail,9);
    tail = addNode(tail,99);
    tail = addNode(tail,9999);
    tail = addNode(tail,99999);
    tail = addNode(tail,999999);
    tail = addNode(tail,99999999);
    
    tail = delAtPos(tail,4);
    
    struct node *ptr = tail->next;
    
    do{
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr!=tail->next);
    
    return 0;
    
    
    
}
