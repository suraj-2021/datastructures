#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Node {
    char *word;                 // The word stored in this node
    int frequency;              // Frequency count for the word
    struct Node *left, *right;  // Pointers to left and right children
} Node;


Node* createNode(const char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    newNode->word = strdup(word);
    if (!newNode->word) {
        printf("Memory allocation failed for word!\n");
        free(newNode);
        exit(1);
    }
    
    newNode->frequency = 1;
    newNode->left = newNode->right = NULL;
    
    return newNode;
}

/* Function to insert a word into the BST or increment its frequency if it exists */
Node* insert(Node* root, const char* word) {
    if (root == NULL) {
        return createNode(word);
    }
    
    int cmp = strcmp(word, root->word);
    
    if (cmp < 0) {
        root->left = insert(root->left, word);
    } else if (cmp > 0) {
        root->right = insert(root->right, word);
    } else {
        root->frequency++;
    }
    
    return root;
}


void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%-20s: %d\n", root->word, root->frequency);
        printInOrder(root->right);
    }
}

/* Function to free the memory used by the BST */
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->word);
        free(root);
    }
}


void toLowerWord(char* word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}


Node* processLine(Node* root, char* line) {
    char word[100];  // Buffer to hold each word
    int wordIndex;   // Index for building the current word
    
    // Process each character in the line
    for (int i = 0; line[i] != '\0'; i++) {
        // Start a new word
        if (isalnum(line[i])) {
            wordIndex = 0;
            
            // Collect all the characters that form this word
            while ((isalnum(line[i]) || line[i] == '\'' || line[i] == '-') && wordIndex < 99) {
                word[wordIndex++] = line[i++];
            }
            
            // We've finished collecting a word
            word[wordIndex] = '\0';  // Null-terminate
            
            // Convert to lowercase and add to our tree
            toLowerWord(word);
            root = insert(root, word);
            
            // Move i back by one since the for loop will increment it
            if (line[i] == '\0') break;
            i--;
        }
    }
    
    return root;
}

int main() {
    FILE *file;
    char filename[100];
    char buffer[1024];  // Buffer to read each line
    Node* root = NULL;  // Root of our binary search tree
    
    //Get the filename from the user
    printf("Enter the name of the text file: ");
    scanf("%99s", filename);
    
    //Open the file
    file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        return 1;
    }
    
    //Process the file one line at a time
    while (fgets(buffer, sizeof(buffer), file)) {
        root = processLine(root, buffer);
    }
    
    // Close the file
    fclose(file);
    
    // Print the results
    printf("\nWord Frequency List (Alphabetical Order):\n");
    printf("======================================\n");
    printf("%-20s: %s\n", "Word", "Frequency");
    printf("--------------------------------------\n");
    printInOrder(root);
    printf("======================================\n");
    
    
    freeTree(root);
    
    return 0;
}
