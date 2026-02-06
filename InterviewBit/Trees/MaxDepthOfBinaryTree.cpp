// https://www.interviewbit.com/problems/max-depth-of-binary-tree/

int Solution::maxDepth(TreeNode* A) {
    if (!A) return 0;
    return max(maxDepth(A -> left), maxDepth(A -> right)) + 1;
}