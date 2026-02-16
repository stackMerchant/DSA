// https://www.interviewbit.com/problems/reverse-level-order/

void trav(TreeNode* A, int level, int &maxLevel, unordered_map<int, vector<int>> &map) {
    if (A == NULL) return;
    maxLevel = max(maxLevel, level);
    
    map[level].push_back(A -> val);
    trav(A -> left, level + 1, maxLevel, map);
    trav(A -> right, level + 1, maxLevel, map);
}

vector<int> Solution::solve(TreeNode* A) {
    unordered_map<int, vector<int>> map;
    int maxLevel = 0;
    trav(A, 0, maxLevel, map);
    vector<int> ans;
    
    for (int i=maxLevel; i>=0; i--) {
        for (auto &v: map[i]) ans.push_back(v);
    }
    return ans;
}
