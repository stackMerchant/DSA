// https://www.interviewbit.com/problems/min-depth-of-binary-tree/

int Solution::minDepth(TreeNode* A) {
    if (!A) return INT_MAX;
    if (A -> left == NULL && A -> right == NULL) return 1;
    
    int left = minDepth(A -> left);
    int right = minDepth(A -> right);
    return 1 + min(left, right);
}