#include<stdio.h>
#include<stdlib.h>


struct node {
      
      int data;
      struct node *next;
};

struct node *createcircular(int data);

int main(){
    
    struct node *tail = NULL;
    
    tail = createcircular(99);
    
    printf("%d\n",tail->data);
    
    return 0;
}

struct node *createcircular(int data){
    
    struct node *temp = malloc(sizeof(struct node));
    temp ->data = data;
    temp ->next = temp;
    
    return temp;
    
}
