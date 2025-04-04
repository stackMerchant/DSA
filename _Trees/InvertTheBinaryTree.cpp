// https://www.interviewbit.com/problems/invert-the-binary-tree/

TreeNode* Solution::invertTree(TreeNode* A) {
    if(!A) return NULL;
    
    TreeNode* invLeft = invertTree(A -> left);
    TreeNode* invRight = invertTree(A -> right);
    
    A -> left = invRight;
    A -> right = invLeft;
    return A;
}