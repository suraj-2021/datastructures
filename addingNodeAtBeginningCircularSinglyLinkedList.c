#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node *addToEmpty(int data){
       struct node *temp = malloc(sizeof(struct node));
       temp ->data = data;
       temp ->next = temp;
       
      return temp;
}

struct node *addAtBeg(struct node *tail, int data){
       struct node *temp = malloc(sizeof(struct node));
       temp ->data = data;
       temp ->next = NULL;
       
       temp->next  = tail->next;
       tail->next = temp;
       
       return tail;
}


void print(struct node *tail){
     struct node *ptr = tail ->next;
     
     do{
         printf("%d\n",ptr->data);
         ptr = ptr->next;
     }
     while(ptr!=tail->next);
}


int main(){
    struct node *tail=NULL;
    
    tail = addToEmpty(99);
    tail = addAtBeg(tail,999);
    
    print(tail);
    
    return 0;
}
