#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
};


struct node *addNode(struct node*tail, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    
    if(tail==NULL){
        temp->next = temp;
        tail = temp;
        
        return tail;
    }
    else {
        temp->next = tail->next;
        tail->next =temp;
        tail = temp;
        
        return tail;
    }
}

struct node *delLast(struct node *tail){
    
    if(tail == NULL){
        return tail;
    }
    
    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return tail;
        
    }
    struct node *ptr = tail->next;
    
    while(ptr->next != tail){
        ptr = ptr->next;
    }
    
    ptr->next = tail->next;
    free(tail);
    tail = ptr;
    
    return tail;
    
}

int main(){
    struct node *tail = NULL;
    
    tail = addNode(tail,9);
    tail = addNode(tail,99);
    tail = addNode(tail,999);
    tail = addNode(tail,9999);
    
    printf("List items before deleting the last Node: \n");
    struct node *ptr = tail->next;
    
       do{
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    while(ptr!=tail->next);
    
    tail = delLast(tail);
    
      printf("\nList items After deleting the last Node: \n");
    ptr = tail->next;
    
    do{
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    while(ptr!=tail->next);
    
   return 0; 
}
