// https://www.interviewbit.com/problems/path-to-given-node/

vector<int> ret;

void trav(TreeNode* a, int b, vector<int>& curr) {
    if (!a) return;
    
    curr.push_back(a -> val);
    if(a -> val == b) {
        ret = curr;
        return;
    }
    
    trav(a -> left, b, curr);
    trav(a -> right, b, curr);
    curr.pop_back();
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> vec;
    trav(A, B, vec);
    return ret;
}