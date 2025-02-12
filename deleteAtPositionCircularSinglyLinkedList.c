#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node *addNode(struct node *tail, int data){
       struct node *temp = malloc(sizeof(struct node));
       temp ->data = data;
       temp ->next = NULL;
       
       if(tail == NULL){
          temp->next = temp;
          tail = temp;
          
          return tail;
       }
       
       temp ->next = tail->next;
       tail->next = temp;
       tail = temp;
       return tail;
}



struct node *delAtPos(struct node*tail,int pos){
       
       if(tail == NULL){
           return tail;
       }
       
       int i=1;
       
       struct node*ptr = tail->next;
       
       while(i<pos-1){
           ptr = ptr->next;
           pos--;
       }
       
       if(ptr->next == tail){
           ptr->next = tail->next;
           free(tail);
           tail = ptr;
           
           return tail;
       }
       
       struct node *ptr2 = ptr->next;
       ptr->next = ptr2->next;
       free(ptr2);
       ptr2 = NULL;
       
       return tail;
}

int main(){
    struct node *tail = NULL;
    
    tail =  addNode(tail,9);
    tail =  addNode(tail,9);
    tail =  addNode(tail,99999);
    tail =  addNode(tail,90);
    
    tail = delAtPos(tail,3);
    
    struct node *ptr =tail->next;
    
    do{
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr!=tail->next);

return 0;
    
}
