// https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

int trav(TreeNode* n, int &ret) {
    if (n == NULL) return 0;
    
    int left = trav(n -> left, ret);
    int right = trav(n -> right, ret);
    
    int thisNode = n -> val;
    int pathFromThisNode = thisNode + max(left, right);
    int maxPathFromThisNode = max(thisNode, pathFromThisNode);

    int pathWithThisNode = thisNode + left + right;
    ret = max(ret, max(pathWithThisNode, maxPathFromThisNode));
    
    return maxPathFromThisNode;
}

int Solution::maxPathSum(TreeNode* A) {
    int ret = INT_MIN;
    trav(A, ret);
    return ret;
}