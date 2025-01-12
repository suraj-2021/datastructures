#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

int main() {
    // Create head node
    struct node *head = (struct node*)malloc(sizeof(struct node));

    head->data = 50;
    head->link = NULL;

    // Create current node
    struct node *current = (struct node*)malloc(sizeof(struct node));

    current->data = 99;
    current->link = NULL;

    // Link head to current
    head->link = current;

    // Print the linked list
    struct node *temp = head;
    while (temp != NULL) {
        printf("Node data: %d\n", temp->data);
        temp = temp->link;
    }

    // Free allocated memory
    free(current);
    free(head);

    return 0;
}
