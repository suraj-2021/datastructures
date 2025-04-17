// Right rotation
AVLNode* rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotation
AVLNode* leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Left-Right double rotation
AVLNode* leftRightRotate(AVLNode *z) {
    // First, perform left rotation on left child
    z->left = leftRotate(z->left);
    
    // Then, perform right rotation on current node
    return rightRotate(z);
}

// Right-Left double rotation
AVLNode* rightLeftRotate(AVLNode *z) {
    // First, perform right rotation on right child
    z->right = rightRotate(z->right);
    
    // Then, perform left rotation on current node
    return leftRotate(z);
}
