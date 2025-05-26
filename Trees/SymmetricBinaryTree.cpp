// https://www.interviewbit.com/problems/symmetric-binary-tree/

bool check(TreeNode* a, TreeNode* b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;
    
    bool hasSameValue = a -> val == b -> val;
    bool isLeftSym = check(a -> left, b -> right);
    bool isRightSym = check(a -> right, b -> left);
    return hasSameValue && isLeftSym && isRightSym;
}

int Solution::isSymmetric(TreeNode* A) {
    if (!A) return 1;
    return check(A -> left, A-> right);
}