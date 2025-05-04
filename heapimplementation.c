#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *left, *right, *parent;
} Node;

typedef struct {
    Node *root, *last;
    int size;
} MinHeap;

Node* createNode(int v) {
    Node* n = malloc(sizeof(Node));
    if (!n) exit(1);
    n->data = v; n->left = n->right = n->parent = NULL;
    return n;
}

MinHeap* initHeap() {
    MinHeap* h = malloc(sizeof(MinHeap));
    if (!h) exit(1);
    h->root = h->last = NULL; h->size = 0;
    return h;
}

Node* findNextParent(MinHeap* h) {
    if (!h->size) return NULL;
    int pos = h->size + 1, path[32], height = 0;
    while (pos > 1) { path[height++] = pos % 2; pos /= 2; }
    Node* cur = h->root;
    for (int i = height - 2; i > 0; i--)
        cur = (path[i] == 0) ? cur->left : cur->right;
    return cur;
}

void swapValues(Node* a, Node* b) {
    int t = a->data; a->data = b->data; b->data = t;
}

void heapifyUp(MinHeap* h, Node* n) {
    while (n != h->root && n->parent && n->data < n->parent->data) {
        swapValues(n, n->parent);
        n = n->parent;
    }
}

void heapifyDown(MinHeap* h, Node* n) {
    Node* s = n;
    if (n->left && n->left->data < s->data) s = n->left;
    if (n->right && n->right->data < s->data) s = n->right;
    if (s != n) {
        swapValues(n, s);
        heapifyDown(h, s);
    }
}

void push(MinHeap* h, int v) {
    Node* n = createNode(v);
    if (!h->size) {
        h->root = h->last = n; h->size++; return;
    }
    Node* p = findNextParent(h);
    if (h->size % 2 == 1) p->left = n; else p->right = n;
    n->parent = p; h->last = n; h->size++;
    heapifyUp(h, n);
}

Node* findNode(MinHeap* h, int pos) {
    int path[32], height = 0;
    while (pos > 1) { path[height++] = pos % 2; pos /= 2; }
    Node* cur = h->root;
    for (int i = height - 1; i >= 0; i--)
        cur = (path[i] == 0) ? cur->left : cur->right;
    return cur;
}

int pop(MinHeap* h) {
    if (!h->size) { printf("Heap is empty!\n"); return INT_MIN; }
    int val = h->root->data;
    if (h->size == 1) {
        free(h->root); h->root = h->last = NULL; h->size--;
        return val;
    }
    h->root->data = h->last->data;
    Node* lastParent = h->last->parent;
    if (lastParent->right == h->last) lastParent->right = NULL;
    else lastParent->left = NULL;
    free(h->last);
    h->size--;
    if (h->size > 0) h->last = findNode(h, h->size);
    else h->last = NULL;
    heapifyDown(h, h->root);
    return val;
}

void printHeap(Node* root) {
    if (!root) return;
    Node* q[1000]; int f=0,r=0;
    q[r++] = root;
    while (f < r) {
        Node* c = q[f++];
        printf("%d ", c->data);
        if (c->left) q[r++] = c->left;
        if (c->right) q[r++] = c->right;
    }
    printf("\n");
}

void freeHeap(Node* root) {
    if (!root) return;
    freeHeap(root->left);
    freeHeap(root->right);
    free(root);
}

int main() {
    MinHeap* h = initHeap();
    push(h,10); push(h,5); push(h,15); push(h,2); push(h,8);
    printf("Heap after pushing elements: ");
    printHeap(h->root);
    printf("Popped: %d\n", pop(h));
    printf("Heap after popping: ");
    printHeap(h->root);
    printf("Popped: %d\n", pop(h));
    printf("Heap after popping: ");
    printHeap(h->root);
    push(h,1);
    printf("Heap after pushing 1: ");
    printHeap(h->root);
    freeHeap(h->root);
    free(h);
    return 0;
}
