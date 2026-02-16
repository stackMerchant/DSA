// https://www.interviewbit.com/problems/consecutive-parent-child/

int check(TreeNode *parent, TreeNode *child) {
    if (child == NULL) return 0;
    if (abs(parent -> val - child -> val) == 1) return 1;
    return 0;
}

int trav(TreeNode *A) {
    if (A == NULL) return 0;
    return check(A, A -> left) + check(A, A -> right) + trav(A -> left) + trav(A -> right);
}

int Solution::consecutiveNodes(TreeNode *A) {
    return trav(A);
}
