// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

// Solution 1 => Using 2 forward and backward stack

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ret;
    TreeNode* top;
    vector<int> currLevel;
    
    stack<TreeNode*> forward, backward;
    forward.push(A);
    
    while (!forward.empty() || !backward.empty()) {
        // Forward
        while (!forward.empty()) {
            top = forward.top(); forward.pop();
            currLevel.push_back(top -> val);
            
            if (top -> left) backward.push(top -> left);
            if (top -> right) backward.push(top -> right);
        }
        if (!currLevel.empty()) ret.push_back(currLevel);
        currLevel.clear();
        
        // Backward
        while (!backward.empty()) {
            top = backward.top(); backward.pop();
            currLevel.push_back(top -> val);
            
            if (top -> right) forward.push(top -> right);
            if (top -> left) forward.push(top -> left);
        }
        if (!currLevel.empty()) ret.push_back(currLevel);
        currLevel.clear();
    }

    return ret;
}

// Solution 2 => Using a deque (for level change => level pair or NULL in queue)

// Solution 3 => Normal level order traversal, reverse alternate
