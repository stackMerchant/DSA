// https://www.interviewbit.com/problems/identical-binary-trees/

int Solution::isSameTree(TreeNode* a, TreeNode* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    return (a -> val == b -> val) && isSameTree(a -> left, b -> left) && isSameTree(a -> right, b -> right);
}