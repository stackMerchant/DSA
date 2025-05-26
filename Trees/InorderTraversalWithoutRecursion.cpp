// https://www.interviewbit.com/problems/inorder-traversal/

vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ret;
    stack<TreeNode*> st;
    TreeNode* curr = A;
    
    while (!st.empty() || curr) {
        if (curr) {
            st.push(curr);
            curr = curr -> left;
        } else {
            curr = st.top(); st.pop();
            ret.push_back(curr -> val);
            curr = curr -> right;
        }
    }
    return ret;
}