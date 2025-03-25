#include<stdio.h>
#include<stdlib.h>
#define n 5

int s1[n];
int s2[n];
int top1=-1;
int top2=-1;
int count=0;

void push1(int data){
     if(top1==n-1){
         printf("STACK OVERFLOW");
         return;
     }
     top1 = top1+1;
     s1[top1] = data;
}

void enqueue(int data){
    push1(data);
    count++;
}

int pop1(){
    if(top1==-1){
        printf("STACK UNDERFLOW!");
        return -1;
    }
    else{
        int a = s1[top1];
        top1 = top1-1;
        return a;
    }
}

int pop2(){
    if(top2==-1){
        printf("STACK UNDERFLOW");
        return -1;
    }
    else{
        int a = s2[top2];
        top2--;
        return a;
    }
    
}


void push2(int data){
     if(top2==n-1){
         printf("STACK OVERFLOW!");
         return ;
     }
     else{
         top2++;
         s2[top2] = data;
     }
}

void dequeue(){
    if(top1==-1){
        printf("STACK UNDERFLOW");
        return;
    }
    
    for(int i=0;i<count;i++){
        int a = pop1();
        push2(a);
    }
    
    int value = pop2();
    printf("DEQUEUED ELEMENT IS: %d\n",value);
    count--;
    
    for(int i=0;i<count;i++){
        int a = pop2();
        push1(a);
    }  
}
void display(){
    if(top1==-1){
        printf("STACK 1 IS EMPTY!");
        return;
    }
    else{
        for(int i=0;i<=top1;i++){
            printf("%d\t",s1[i]);
        }
    }
}
int main(){
    enqueue(9);
    enqueue(99);
    enqueue(999);
    
    printf("Elements in the Stack 1: \n");
    display();
    dequeue();
    printf("Elements in the Stack 1 after qeueuing: \n");
    display();
    
    return 0;
}

