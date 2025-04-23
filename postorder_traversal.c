def postorder_traversal(root):
    # Base case: if node is None, return
    if root is None:
        return
    
    # First recursively traverse left subtree
    postorder_traversal(root.left)
    
    # Then recursively traverse right subtree
    postorder_traversal(root.right)
    
    # Finally visit the current node
    print(root.value)  # or process the node in some way
