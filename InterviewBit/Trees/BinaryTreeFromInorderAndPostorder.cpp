// https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/

int findIndex(vector<int> &vec, int element, int a, int b) {
    for (int i = a; i <= b; i++) if (vec[i] == element) return i;
    return -1;
}

TreeNode* build(vector<int> &inorder, int ia, int ib, vector<int> &postorder, int pa, int pb) {
    if (ia > ib || pa > pb) return NULL;
    
    int keyVal = postorder[pb]; // Last element in postorder is root
    int iKey = findIndex(inorder, keyVal, ia, ib); // Find root in inorder
    int pKey = pa + iKey - ia - 1; // pa to pKey index elements will be in left subtree
    
    TreeNode* node = new TreeNode(keyVal);
    node -> left = build(inorder, ia, iKey - 1, postorder, pa, pKey);
    node -> right = build(inorder, iKey + 1, ib, postorder, pKey + 1, pb - 1);
    return node;
}

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
}