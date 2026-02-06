// https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/

bool isLeaf(TreeNode* A) {
    return A -> left == NULL && A -> right == NULL;
}

void trav(TreeNode* A, vector<int> &parentElements, int &sumOfParents, int &target, vector<vector<int>> &ret) {
    if (!A) return;
    
    // Add current element
    parentElements.push_back(A -> val); sumOfParents += A -> val;
    
    // If at leaf, check if sum == target and add to result
    if (isLeaf(A) && sumOfParents == target) ret.push_back(parentElements);
    
    // Traverse
    trav(A -> left, parentElements, sumOfParents, target, ret);
    trav(A -> right, parentElements, sumOfParents, target, ret);
    
    // Remove current element
    parentElements.pop_back(); sumOfParents -= A -> val;
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int target) {
    vector<vector<int>> ret;
    vector<int> parentElements;
    int sumOfParents = 0;
    trav(A, parentElements, sumOfParents, target, ret);
    return ret;
}