// https://www.interviewbit.com/problems/path-sum/

bool isLeaf(TreeNode* A) {
    return A -> left == NULL && A -> right == NULL;
}

int Solution::hasPathSum(TreeNode* A, int B) {
    if (!A) return false;
    int leftOver = B - A -> val;
    if (isLeaf(A) && leftOver == 0) return true;
    return hasPathSum(A -> left, leftOver) || hasPathSum(A -> right, leftOver);
}