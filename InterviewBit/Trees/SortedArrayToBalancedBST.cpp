// https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

TreeNode* build(const vector<int> &A, int a, int b) {
    if (a > b) return NULL;

    int key = a + (b - a + 1) / 2;
    TreeNode* node = new TreeNode(A[key]);
    node -> left = build(A, a, key - 1);
    node -> right = build(A, key + 1, b);
    return node;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return build(A, 0, A.size() - 1);
}