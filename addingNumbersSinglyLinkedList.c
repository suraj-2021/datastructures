#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
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

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to add two numbers represented by linked lists
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    struct Node* temp = NULL;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        if (result == NULL) {
            result = createNode(sum);
            temp = result;
        } else {
            temp->next = createNode(sum);
            temp = temp->next;
        }
    }

    return result;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the above functions
int main() {
    // Create first number 342 as 2 -> 4 -> 3
    struct Node* num1 = NULL;
    insertAtEnd(&num1, 2);
    insertAtEnd(&num1, 4);
    insertAtEnd(&num1, 3);

    // Create second number 465 as 5 -> 6 -> 4
    struct Node* num2 = NULL;
    insertAtEnd(&num2, 5);
    insertAtEnd(&num2, 6);
    insertAtEnd(&num2, 4);

    printf("Number 1: ");
    printList(num1);

    printf("Number 2: ");
    printList(num2);

    // Add the two numbers
    struct Node* sum = addTwoNumbers(num1, num2);

    printf("Sum: ");
    printList(sum);

    return 0;
}
