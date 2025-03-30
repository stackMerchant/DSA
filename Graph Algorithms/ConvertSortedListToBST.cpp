// https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

TreeNode* create(vector<int> &items, int i, int j) {
    if (i > j) return NULL;
    
    int mid = (i + j) / 2;
    TreeNode* ret = new TreeNode(items[mid]);
    ret -> left = create(items, i, mid - 1);
    ret -> right = create(items, mid + 1, j);
    return ret;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    vector<int> items;
    while (A != NULL) {
        items.push_back(A -> val);
        A = A -> next;
    }
    
    return create(items, 0, items.size() - 1);
}