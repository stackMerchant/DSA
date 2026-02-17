// https://www.interviewbit.com/problems/diagonal-traversal/

vector<int> Solution::solve(TreeNode* A) {
    TreeNode* curr = A;
    vector<int> ans;
    queue<TreeNode*> q;
    
    while (curr || !q.empty()) {
        if (curr == NULL) {
            curr = q.front(); q.pop();
        }
        
        if (curr -> left) q.push(curr -> left);
        ans.push_back(curr -> val);
        curr = curr -> right;
    }
    return ans;
}
