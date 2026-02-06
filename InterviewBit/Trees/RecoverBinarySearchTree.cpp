// https://www.interviewbit.com/problems/recover-binary-search-tree/

void trav(TreeNode* curr, TreeNode* &prev, TreeNode* &node1, TreeNode* &node2) {
    if (curr == NULL) return;
    trav(curr -> left, prev, node1, node2);
    
    // If there is a dip in value
    if (prev != NULL && curr -> val < prev -> val) {
        // If it is first time, then prev node is one which is changed
        if (node1 == NULL) node1 = prev;
        // The node with dip is second one which is changed
        node2 = curr;
    }

    prev = curr;
    trav(curr -> right, prev, node1, node2);
}

vector<int> Solution::recoverTree(TreeNode* A) {
    TreeNode *node1 = NULL, *node2 = NULL, *prev = NULL;
    trav(A, prev, node1, node2);
    return { node2 -> val, node1 -> val };
}