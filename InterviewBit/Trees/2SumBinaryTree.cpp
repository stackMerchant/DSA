// https://www.interviewbit.com/problems/2sum-binary-tree/

int trav(TreeNode* A, int &B, unordered_set<int> &set) {
    // Check null
    if (A == NULL) return 0;
    // Check if complement is already present
    if (set.find(A -> val) != set.end()) return 1;
    // Insert the compliment
    set.insert(B - (A -> val));
    // Traverse left and right
    if (trav(A -> left, B, set) || trav(A -> right, B, set)) return 1;
    return 0;
}

int Solution::t2Sum(TreeNode* A, int B) {
    unordered_set<int> set;
    return trav(A, B, set);
}
