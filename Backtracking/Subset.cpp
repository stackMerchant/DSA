// https://www.interviewbit.com/problems/subset/

// Solution 1

void trav(int i, vector<int> &currList, vector<int> &A, vector<vector<int>> &ans) {
    if (i >= A.size()) return;
    
    // With this element
    currList.push_back(A[i]);
    ans.push_back(currList);
    trav(i+1, currList, A, ans);
    currList.pop_back();
    
    // Without this element
    trav(i+1, currList, A, ans);
}

vector<vector<int>> Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    
    vector<vector<int>> ans;
    ans.push_back({});
    
    vector<int> currList;
    trav(0, currList, A, ans);
    return ans;
}

// Solution 2, not much recommended, doesn't holds up well for follow ups

void trav(int idx, vector<int> &currList, vector<int> &A, vector<vector<int>> &ans){
    ans.push_back(currList);
    for (int i=idx; i<A.size(); i++) {
        currList.push_back(A[i]);
        trav(i+1, currList, A, ans);
        currList.pop_back();
    }
}

vector<vector<int>> Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> currList;
    trav(0, currList, A, ans);
    return ans;
}