// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

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