#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int queue[MAX]; 
int front = -1; 
int rear = -1; 

//check if the queue is empty
bool isEmpty() {
    return front == -1;
}

//check if the queue is full
bool isFull() {
    return rear == MAX - 1;
}

// t add an element
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = 0; // Set front to 0 when the first element is added
    }
    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// to remove an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return -1 to indicate that the queue is empty
    }
    int item = queue[front];
    
    // If there's only one element, reset the queue
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    
    printf("Dequeued: %d\n", item);
    return item;
}

// Function to display
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    
    display();
    
    dequeue();
    
    display();
    
    enqueue(40);
    
    display();
    
    return 0;
}
