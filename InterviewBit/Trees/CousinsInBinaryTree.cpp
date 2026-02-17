// https://www.interviewbit.com/problems/cousins-in-binary-tree/

// Solution Reference: https://www.youtube.com/watch?v=PhgPX7HlyTo

bool isEqual(TreeNode* A, int B) {
    if (A == NULL) return false;
    return A -> val == B;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if (isEqual(A -> left, B) || isEqual(A -> right, B)) return ans;
    
    queue<TreeNode*> q;
    q.push(A);
    bool targetFound = false;
    while (!q.empty() && !targetFound) {
        int size = q.size();
        for (int i=0; i<size; i++) {
            TreeNode* front = q.front(); q.pop();
            
            if (isEqual(front -> left, B) || isEqual(front -> right, B)) {
                targetFound = true;
            } else {
                if (front -> left) q.push(front -> left);
                if (front -> right) q.push(front -> right);
            }
        }
    }
    
    while (!q.empty()) {
        ans.push_back(q.front() -> val);
        q.pop();
    }
    return ans;
}
