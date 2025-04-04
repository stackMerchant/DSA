// https://www.interviewbit.com/problems/remove-half-nodes/

TreeNode* Solution::solve(TreeNode* A) {
    if(A->left == NULL && A->right == NULL)return A;
    if(A->left == NULL)
        return solve(A->right);
    if(A->right == NULL)
        return solve(A->left);
    A->left = solve(A->left);
    A->right = solve(A->right);
    return A;   
}