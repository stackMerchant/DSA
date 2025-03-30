// https://www.interviewbit.com/problems/level-order/

void trav(vector<vector<int>> &ret, TreeNode* currNode, int currLevel) {
    if (currNode == NULL) return;
    
    if (currLevel > (int)(ret.size() - 1)) ret.push_back(vector<int>(1, currNode -> val));
    else ret[currLevel].push_back(currNode -> val);
    
    trav(ret, currNode -> left, currLevel + 1);
    trav(ret, currNode -> right, currLevel + 1);
    return;
}

vector<vector<int>> Solution::levelOrder(TreeNode* A) {
    vector<vector<int>> ret;
    trav(ret, A, 0);
    return ret;
}