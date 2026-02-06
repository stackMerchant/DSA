// Code for AVL tree, just skeleton, not a working code

TreeNode* rotateRight(TreeNode* root) {
    TreeNode* newRoot = root -> left;
    root -> left = newRoot -> right;
    newRoot -> right = root;
    return newRoot;
}

TreeNode* rotateLeft(TreeNode* root) {
    TreeNode* newRoot = root -> right;
    root -> right = newRoot -> left;
    newRoot -> left = root;
    return newRoot;
}

TreeNode* AVLInsert(TreeNode* root, int value) {
    if (root == NULL) return new TreeNode(value);

    // Regular insert
    if (value < root -> val)
        root -> left = AVLInsert(root -> left, value);
    else
        root -> right = AVLInsert(root -> right, value);

    // AVL stuff
    int balance = height(root -> left) - height(root -> right);
    if (balance > 1) { // L
        if (height(root -> left -> left) >= height(root -> left -> right)) // LL
            return rotateRight(root);
        else { // LR
            root -> left = rotateLeft(root -> left);
            return rotateRight(root);
        }
    }
    if (balance < -1) { // R
        if (height(root -> right -> right) >= height(root -> right -> left)) // RR
            return rotateLeft(root);
        else { // RL
            root -> right = rotateRight(root -> right);
            return rotateLeft(root);
        }
    }
    
    root -> height = 1 + max(left, right);
    return root;
}