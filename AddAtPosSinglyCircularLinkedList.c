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

struct node *addAtBeg(struct node *tail,int data){
       struct node *temp = malloc(sizeof(struct node));
       temp ->data = data;
       temp->next =  NULL;
       
       temp->next = tail->next;
       tail->next = temp;
       
       return tail;
}

void print(struct node *tail){
     struct node *ptr = tail ->next;
     
     do{
         printf("%d\n",ptr->data);
         ptr = ptr->next;
     }while(ptr!=tail->next);
}

fstruct node *addAtPos(struct node *tail,int pos,int data){
       struct node *temp = malloc(sizeof(struct node));
       temp ->data= data;
       temp->next = NULL;
       
       struct node *ptr = tail->next;
       int i=1;
       
       while(i<pos){
           ptr = ptr->next;
           pos--;
       }
       
       if(ptr==tail){
           temp->next = ptr->next;
           ptr->next = temp;
           tail = tail->next;
       }
       else{
           temp->next = ptr->next;
           ptr->next = temp;
           }
           
        return tail;
       
}

int main(){
    struct node *tail;
    
    tail = addToEmpty(9);
    tail = addAtBeg(tail,99);
    tail = addAtBeg(tail,999);
    
    tail = addAtPos(tail,2,1000);
    
    print(tail);
    
    return 0;
}
