// https://www.interviewbit.com/problems/right-view-of-binary-tree/

void traverseAndFill(TreeNode* a, vector<int> &ret, int level) {
    if (!a) return;
    ret[level] = a -> val;
    traverseAndFill(a -> left, ret, level + 1);
    traverseAndFill(a -> right, ret, level + 1);    
    return;
}

int getDepth(TreeNode* a) {
    if (!a) return 0;
    return max(getDepth(a -> left), getDepth(a -> right)) + 1;
}

vector<int> Solution::solve(TreeNode* A) {    
    int depth = getDepth(A);
    vector<int> ret(depth, -1);
    traverseAndFill(A, ret, 0);
    return ret;
}