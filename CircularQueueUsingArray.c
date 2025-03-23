#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear =-1;

void enqueue(int data){
    if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=data;
    }
    else if((rear+1)%MAX == front){
        printf("Queue Is full!");
    }
    else{
        rear = (rear+1)%MAX;
        queue[rear] = data;
    }
}


void dequeue(){
    if(front==-1&&rear==-1){
        printf("Queue is Empty!");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        
        front = (front+1)%MAX;
    }
}

void display(){
     if(front ==-1 && rear==-1){
         printf("Queue is Empty!");
     }
     else{
         int i=front;
         while(i!=rear){
             printf("%d\t",queue[i]);
             i=(i+1)%MAX;
         }
         printf("\t%d\t",queue[rear]);
     }
}

int main(){
    enqueue(9);
    enqueue(99);
    enqueue(999);
    display();
    
    return 0;
}
