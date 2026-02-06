// https://www.interviewbit.com/problems/next-greater-number-bst/

// Solution 1

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    queue<TreeNode*> q;
    if (A) q.push(A);
    TreeNode* ret = NULL;
    
    while(!q.empty()) {
        TreeNode* curr = q.front(); q.pop();
        if (B < curr -> val) {
            ret = curr;
            if (curr -> left) q.push(curr -> left);
        } else {
            if (curr -> right) q.push(curr -> right);
        }
    }
    return ret;
}

// Solution 2

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    TreeNode *curr = A, *ret = NULL;
    while (curr != NULL) {
        if (B < curr -> val) {
            ret = curr;
            curr = curr -> left;
        } else {
            curr = curr -> right;
        }
    }
    return ret;
}