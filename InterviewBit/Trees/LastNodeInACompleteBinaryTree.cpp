// https://www.interviewbit.com/problems/last-node-in-a-complete-binary-tree/

bool trav(TreeNode* A, int level, int &maxLevel, int &ans) {
    if (A == NULL) return false;

    if (level == maxLevel) {
        ans = A -> val;
        return true;
    }

    if (trav(A -> right, level + 1, maxLevel, ans)) return true;
    if (trav(A -> left, level + 1, maxLevel, ans)) return true;
    return false;
}

int Solution::lastNode(TreeNode* A) {
    int maxLevel = 0;
    TreeNode* curr = A;
    while (curr != NULL) {
        curr = curr -> left;
        maxLevel++;
    }
    int ans = -1;
    trav(A, 1, maxLevel, ans);
    return ans;
}
