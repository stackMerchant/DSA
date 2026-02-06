// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

// Solution 1, in O(n)
// The idea is to flatten recursively and return first and last node and form chain

pair<TreeNode*, TreeNode*> flat(TreeNode* first) {
    if (first -> left == NULL && first -> right == NULL) {
        return {first, first};
    }
    
    if (first -> left == NULL) {
        auto [rightFirst, rightLast] = flat(first -> right);
        return {first, rightLast};
    }
    
    if (first -> right == NULL) {
        auto [leftFirst, leftLast] = flat(first -> left);
        first -> left = NULL;
        first -> right = leftFirst;
        return {first, leftLast};
    }
    
    auto [leftFirst, leftLast] = flat(first -> left);
    auto [rightFirst, rightLast] = flat(first -> right);
    first -> left = NULL;
    first -> right = leftFirst;
    leftLast -> right = rightFirst;
    return {first, rightLast};
}

TreeNode* Solution::flatten(TreeNode* A) {
    return flat(A).first;
}


// Solution 2, not O(n)

TreeNode* Solution::flatten(TreeNode* A) {
    if (!A) return NULL;
    
    // Flatten both children
    TreeNode* flatLeft = flatten(A -> left);
    TreeNode* flatRight = flatten(A -> right);

    A -> left = NULL; // Remove left
    A -> right = flatLeft; // Add flatLeft to right
    
    // Go to bottom of right
    TreeNode* curr = A;
    while (curr -> right) curr = curr -> right;
    
    // Add flatRight at bottom
    curr -> right = flatRight;
    
    return A;
}
