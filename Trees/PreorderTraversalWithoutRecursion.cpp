// https://www.interviewbit.com/problems/preorder-traversal/

vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ret;
    stack<TreeNode*> st;
    st.push(A);
    
    TreeNode* top;
    while (!st.empty()) {
        top = st.top(); st.pop();
        
        ret.push_back(top -> val);
        if (top -> right) st.push(top -> right);
        if (top -> left) st.push(top -> left);
    }
    return ret;
}