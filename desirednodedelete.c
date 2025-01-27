#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//delete a node at a given position
void deleteNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    // If the head needs to be removed
    if (position == 0) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL) {
        printf("Position does not exist.\n");
        return;
    }

    // Node temp->next is the node to be deleted
    struct Node* next = temp->next->next;

    free(temp->next); // Free memory
    temp->next = next; // Unlink the deleted node from list
}

// Main function to demonstrate the functionality
int main() {
    struct Node* head = NULL;

    // Inserting nodes into the linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    
    printf("Original Linked List:\n");
    displayList(head);

    int position;
    
    // Ask user for position to delete
    printf("Enter position to delete (0-based index): ");
    scanf("%d", &position);

    deleteNode(&head, position);

    printf("Linked List after deletion:\n");
    displayList(head);

    return 0;
}
