// https://www.interviewbit.com/problems/nodes-at-distance-k/

void trav(TreeNode* curr, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> &parentMap, int B, TreeNode* &target) {
    if (curr == NULL) return;
    
    if (curr -> val == B) target = curr; // save target node
    parentMap[curr] = parent; // set parent
    parentMap[curr] = parent; // set parent
    if (curr -> left) trav(curr -> left, curr, parentMap, B, target);
    if (curr -> right) trav(curr -> right, curr, parentMap, B, target);
}

void dfs(TreeNode* curr, unordered_map<TreeNode*, TreeNode*> &parentMap, unordered_set<TreeNode*> &visitedSet, int dist, vector<int> &ans) {
    if (curr == NULL) return; // null node
    if (visitedSet.find(curr) != visitedSet.end()) return; // already visited

    visitedSet.insert(curr); // mark visted
    if (dist == 0) { // if reached C distance
        ans.push_back(curr -> val);
        return;
    }

    dfs(curr -> left, parentMap, visitedSet, dist - 1, ans); // visit left
    dfs(curr -> right, parentMap, visitedSet, dist - 1, ans); // visit right
    dfs(parentMap[curr], parentMap, visitedSet, dist - 1, ans); // visit parent
}

vector<int> Solution::distanceK(TreeNode* A, int B, int C) {
    unordered_map<TreeNode*, TreeNode*> parentMap; // parent map for traversal
    TreeNode* target; // target node to start dfs from
    trav(A, NULL, parentMap, B, target);
    
    vector<int> ans;
    unordered_set<TreeNode*> visitedSet;
    dfs(target, parentMap, visitedSet, C, ans);
    return ans;
}