// https://www.interviewbit.com/problems/least-common-ancestor/

bool trav(TreeNode* node, int a, int b, int &ret) {
    if (!node) return false;

    // NOTE: No duplicates in tree
    bool isSelf = node -> val == a || node -> val == b; // If node is equal to a or b
    bool isLeft = trav(node -> left, a, b, ret); // If left has a or b
    bool isRight = trav(node -> right, a, b, ret); // If right has a or b

    bool isLCA = (isLeft && isRight) // If left and right both has value
        || (isSelf && (isLeft || isRight)) // If node is equal to a or b AND one of left/right has a/b
        || (isSelf && (a == b)); // If node is equal to a or b AND a == b
    if (isLCA) ret = node -> val; // If lca, save it

    return isSelf || isLeft || isRight; // Return if this node has a/b
}

int Solution::lca(TreeNode* root, int a, int b) {
    int ret = -1;
    trav(root, a, b, ret);
    return ret;
}