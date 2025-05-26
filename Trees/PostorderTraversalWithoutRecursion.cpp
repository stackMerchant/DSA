// https://www.interviewbit.com/problems/postorder-traversal/

/* Post order is same as pre order with right as more importance and at last reverse the array */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> ret;
    stack<TreeNode*> st;
    TreeNode* top;
    
    if (A) st.push(A);

    while (!st.empty()) {
        top = st.top(); st.pop();
        ret.push_back(top -> val);
        
        if (top -> left) st.push(top -> left);
        if (top -> right) st.push(top -> right);
    }
    
    reverse(ret.begin(), ret.end());
    return ret;
}