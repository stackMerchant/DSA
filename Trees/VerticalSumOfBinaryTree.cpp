// https://www.interviewbit.com/problems/vertical-sum-of-a-binary-tree/

void trav(TreeNode* A, int level, map<int, int> &map) {
    if (!A) return;
    
    if (map.find(level) == map.end()) map[level] = 0;
    map[level] = map[level] + A -> val;
    
    trav(A -> left, level - 1, map);
    trav(A -> right, level + 1, map);
    return;
}

vector<int> Solution::verticalSum(TreeNode* A) {
    map<int, int> map;
    trav(A, 0, map);
    
    vector<int> ret;
    for (auto m: map) ret.push_back(m.second);
    return ret;
}