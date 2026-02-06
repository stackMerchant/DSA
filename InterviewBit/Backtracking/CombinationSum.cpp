// https://www.interviewbit.com/problems/combination-sum/

void trav(int i, int currSum, vector<int> &currList, vector<vector<int>> &ans, vector<int> &A, int &B) {
    if (currSum == B) {
        ans.push_back(currList);
        return;
    }
    if (i >= A.size()) return;
    
    // With this element
    if (currSum + A[i] <= B) {
        currList.push_back(A[i]);
        trav(i, currSum + A[i], currList, ans, A, B);
        currList.pop_back();
    }
    
    // Without this element
    trav(i+1, currSum, currList, ans, A, B);
}

vector<vector<int>> Solution::combinationSum(vector<int> &A, int B) {
    // Remember to make it unique
    unordered_set<int> set;
    for (auto &a: A) set.insert(a);
    A.clear();
    for (auto &s: set) A.push_back(s);
    
    sort(A.begin(), A.end());
    
    vector<vector<int>> ans;
    vector<int> currList;
    int currSum = 0;
    
    trav(0, currSum, currList, ans, A, B);
    return ans;
}
