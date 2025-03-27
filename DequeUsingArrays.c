#include<stdio.h>
#define n 5

int deque[n];
int front=-1;
int rear  = -1;


void enquefront(int data){
     if(front==rear+1||front==0&&rear==n-1){
         printf("Deque is full!");
     }
     else if(front==0){
         front = n-1;
         deque[front]=data;
     }
     else{
         front--;
         deque[front]=data;
     }
}

void dequefront(){
     if(front==-1&&rear==-1){
         printf("Dwque is empty!");
         
     }
     else if(front==rear){
         front=rear=-1;
     }
     else if(front==n-1){
         front=0;
         
     }
     else{
         front++;
     }
}

void enquerear(int data){
     if(front==rear+1||(front==0&&rear==n-1)){
         printf("Deque is full!");
     }
     else if(rear==n-1){
         rear=0;
         deque[rear]=data;
     }
     else{
         rear++;
         deque[rear]=data;
     }
    
}

void dequerear(){
     if(front==-1&&rear==-1){
         printf("Deque is empty!");
     }
     else if(front==rear){
         front=rear=-1;
     }
     else if(rear==0){
         rear=n-1;
         
     }
     else{
         rear--;
     }
}

void display(){
    printf("Current elements in the deque are: \n");
    int i=front;
    int j=rear;
    while(i!=j){
        printf("%d\t",deque[i]);
        i = (i+1)%n;
    }
}

int main(){
    enquefront(9);
    enquefront(99);
    enquefront(999);
    display();
    
    return 0;
}
