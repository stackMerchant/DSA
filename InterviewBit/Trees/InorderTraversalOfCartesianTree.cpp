// https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

TreeNode* build(vector<int> &A, int i, int j) {
    if (i > j) return NULL;
    
    // Find max element index
    int maxIdx = i;
    for (int k=i; k<=j; k++) if (A[k] > A[maxIdx]) maxIdx = k;
    // Prepare node
    TreeNode* node = new TreeNode(A[maxIdx]);
    node -> left = build(A, i, maxIdx - 1);
    node -> right = build(A, maxIdx + 1, j);
    return node;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    return build(A, 0, A.size() - 1);
}