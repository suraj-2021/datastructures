#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front =-1;
int rear =-1;


void enqueue(int data){
    if(rear == MAX-1){
        printf("OVERFLOW");
        exit(-1);
    }
    else if(rear == -1 && front == -1){
        rear=rear+1;
        front=front+1;
        
        queue[rear] = data;
    }
    else{
        rear = rear+1;
        queue[rear] = data;
    }
    
}

void dequeue(){
    if(front==-1 && rear==-1){
        printf("UNDERFLOW");
        exit(-1);
    }
    
    front++;
}

void display(){
    if(front==-1&&rear==-1){
        printf("UNDERFLOW");
        exit(-1);
    }
    int i=front;
    while(queue[i]!='\0'){
        printf("%d\t",queue[i]);
        i++;
    }
    printf("\n");
    
}

void peek(){
    if(front==-1&&rear==-1){
        printf("UNDERFLOW");
        exit(-1);
    }
    
    printf("\n %d is the front element int the queue!\n",queue[front]);
}


int main(){
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    
    display();
    
    dequeue();
    
    display();
    
    peek();
    
    return 0;
    
    
}
