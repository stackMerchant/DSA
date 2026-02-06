// https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

int findIndex(vector<int> &vec, int element, int a, int b) {
    for (int i = a; i <= b; i++) if (vec[i] == element) return i;
    return -1;
}

TreeNode* build(vector<int> &preorder, int pa, int pb, vector<int> &inorder, int ia, int ib) {
    if (pa > pb || ia > ib) return NULL;
    
    int keyVal = preorder[pa]; // First element in preorder is root
    int ikey = findIndex(inorder, keyVal, ia, ib); // Find root in inorder
    int pKey = pa + ikey - ia; // pa + 1 to pKey index elements will be in left subtree
    
    TreeNode* node = new TreeNode(keyVal);
    node -> left = build(preorder, pa + 1, pKey, inorder, ia, ikey - 1);
    node -> right = build(preorder, pKey + 1, pb, inorder, ikey + 1, ib);
    return node;
}

TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}