// https://www.interviewbit.com/problems/construct-bst-from-preorder/

TreeNode* construct(vector<int> &A, int &idx, int min, int max) {
    if (idx >= A.size()) return NULL;
    
    int a = A[idx];
    if (min >= max || a < min || a > max) return NULL;
    
    TreeNode* node = new TreeNode(a); idx++;
    node -> left = construct(A, idx, min, a);
    node -> right = construct(A, idx, a, max);
    return node;
}

TreeNode* Solution::constructBST(vector<int> &A) {
    int idx = 0;
    return construct(A, idx, INT_MIN, INT_MAX);
}
