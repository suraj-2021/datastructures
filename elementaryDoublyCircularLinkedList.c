#include<stdio.h>
#include<stdlib.h>


struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *createcircular(int data);

int main(){
    struct node *tail = NULL;
    
    tail = createcircular(999);
    
    printf("%d\n",tail->data);
    
    return 0;
}

struct node *createcircular(int data){
       struct node *temp = malloc(sizeof(struct node));
       temp ->prev = temp;
       temp ->data = data;
       temp ->next= temp;
       
       return temp;
}
