#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void enqueue(struct node **front, struct node **rear, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (*front == NULL && *rear == NULL) {
        *front = *rear = temp;
    } else {
        (*rear)->next = temp;
        (*rear) = temp;
    }
}

void dequeue(struct node **front, struct node **rear) {
    if (*front == NULL && *rear == NULL) {
        printf("UnderFlow\n");
        exit(-1);
    } else {
        struct node *temp = *front;
        *front = (*front)->next;

        if (*front == NULL) {  // If queue becomes empty after dequeue
            *rear = NULL;
        }

        free(temp);
        temp = NULL;
    }
}

void display(struct node **front) {
    struct node *temp = *front;
    while (temp != NULL) {
        printf("%d\t", temp->data);  
        temp = temp->next;         
    }
    printf("\n");  // Add a newline for better formatting
}

int main() {
    struct node *front = NULL;
    struct node *rear = NULL;

    enqueue(&front, &rear, 9);
    enqueue(&front, &rear, 99);
    display(&front);

    enqueue(&front, &rear, 999);
    display(&front);

    dequeue(&front, &rear);  
    display(&front);

    return 0; 
}
