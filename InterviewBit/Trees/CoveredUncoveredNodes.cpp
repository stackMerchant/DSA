// https://www.interviewbit.com/problems/covered-uncovered-nodes/

long Solution::coveredNodes(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    long ans = 0; // covered and uncovered count
    
    while (!q.empty()) {
        int size = q.size();
        
        // For left most node on this level
        TreeNode* front = q.front(); q.pop();
        ans += front -> val;
        if (front -> left) q.push(front -> left);
        if (front -> right) q.push(front -> right);
        
        // For middle nodes on this level
        for (int i=0; i<size-2; i++) {
            TreeNode* front = q.front(); q.pop();
            ans -= front -> val;
            if (front -> left) q.push(front -> left);
            if (front -> right) q.push(front -> right);
        }
        
        // For last node on this level
        if (size > 1) {
            TreeNode* front = q.front(); q.pop();
            ans += front -> val;
            if (front -> left) q.push(front -> left);
            if (front -> right) q.push(front -> right);
        }
    }
    return abs(ans);
}
