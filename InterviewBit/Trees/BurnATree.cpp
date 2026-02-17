// https://www.interviewbit.com/problems/burn-a-tree/

void trav(TreeNode* curr, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> &parentMap, int B, TreeNode* &target) {
    if (curr == NULL) return;
    
    if (curr -> val == B) target = curr; // save target node
    parentMap[curr] = parent; // set parent
    parentMap[curr] = parent; // set parent
    if (curr -> left) trav(curr -> left, curr, parentMap, B, target);
    if (curr -> right) trav(curr -> right, curr, parentMap, B, target);
}

void dfs(TreeNode* curr, unordered_map<TreeNode*, TreeNode*> &parentMap, unordered_set<TreeNode*> &visitedSet, int level, int &maxLevel) {
    if (curr == NULL) return; // null node
    if (visitedSet.find(curr) != visitedSet.end()) return; // already visited

    visitedSet.insert(curr); // mark visted
    maxLevel = max(maxLevel, level); // update level

    dfs(curr -> left, parentMap, visitedSet, level + 1, maxLevel); // visit left
    dfs(curr -> right, parentMap, visitedSet, level + 1, maxLevel); // visit right
    dfs(parentMap[curr], parentMap, visitedSet, level + 1, maxLevel); // visit parent
}

int Solution::solve(TreeNode* A, int B) {
    unordered_map<TreeNode*, TreeNode*> parentMap; // parent map for traversal
    TreeNode* target; // target node to start dfs from
    trav(A, NULL, parentMap, B, target);
    
    int maxLevel = 0;
    unordered_set<TreeNode*> visitedSet;
    dfs(target, parentMap, visitedSet, 0, maxLevel);
    
    return maxLevel;
}
