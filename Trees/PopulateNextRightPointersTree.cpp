// https://www.interviewbit.com/problems/populate-next-right-pointers-tree/

// Solution 1

// levelToNodeMap is a map of level to leftmost node at that level, initially all NULL
void trav(TreeLinkNode* node, int level, unordered_map<int, TreeLinkNode*> &levelToNodeMap) {
    if (!node) return;
    
    node -> next = levelToNodeMap.find(level) == levelToNodeMap.end() ? NULL : levelToNodeMap[level]; // Assign next
    levelToNodeMap[level] = node; // Make current node left most node on current level
    trav(node -> right, level + 1, levelToNodeMap);
    trav(node -> left, level + 1, levelToNodeMap);
}

void Solution::connect(TreeLinkNode* A) {
    unordered_map<int, TreeLinkNode*> levelToNodeMap;
    trav(A, 0, levelToNodeMap);
}

// Solution 2

void Solution::connect(TreeLinkNode* A) {
    if (!A) return;
    
    queue<pair<TreeLinkNode*, int>> q;
    q.push({A, 0});
    while (!q.empty()) {
        // Pop a node and its level
        pair<TreeLinkNode*, int> front = q.front(); q.pop();
        TreeLinkNode* frontNode = front.first;
        int frontNodeLevel = front.second;
        
        // If popped node's level == front node's level, add next link
        if (!q.empty() && (q.front().second == frontNodeLevel)) frontNode -> next = q.front().first;
        
        // Add children to queue
        if (frontNode -> left) q.push({frontNode -> left, frontNodeLevel + 1});
        if (frontNode -> right) q.push({frontNode -> right, frontNodeLevel + 1});
    }
}