// https://www.interviewbit.com/problems/balanced-binary-tree/

int getDepth(TreeNode* node, int &ret) {
    if (!node) return 0;
    int leftDepth = getDepth(node -> left, ret);
    int rightDepth = getDepth(node -> right, ret);
    
    if (abs(leftDepth - rightDepth) > 1) ret = 0;
    return 1 + max(leftDepth, rightDepth);
}

int Solution::isBalanced(TreeNode* A) {
    int ret = 1;
    getDepth(A, ret);
    return ret;
}
