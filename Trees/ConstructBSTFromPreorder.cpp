// https://www.interviewbit.com/problems/construct-bst-from-preorder/

int id;

TreeNode* construct(vector<int> &A, int min, int max) {
    int n = A.size();
    if (id >= n) return NULL;
    
    int key = A[id];
    if (key <= min || key >= max) return NULL;
    TreeNode* node = new TreeNode(key);
    id++;
    
    node -> left = construct(A, min, key);
    node -> right = construct(A, key, max);
    return node;
}

TreeNode* Solution::constructBST(vector<int> &A) {
    id = 0;
    return construct(A, INT_MIN, INT_MAX);
}
