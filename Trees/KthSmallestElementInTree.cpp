// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

int b, ret;
 
void traverse(TreeNode* a) {
    if(a == NULL) return;
    
    traverse(a -> left);
    b--;
    if (b==0) ret = a -> val;
    else traverse(a -> right);
}
 
int Solution::kthsmallest(TreeNode* A, int B) {
    b = B;
    traverse(A);
    return ret;
}