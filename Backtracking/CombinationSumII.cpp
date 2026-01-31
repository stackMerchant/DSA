// https://www.interviewbit.com/problems/combination-sum-ii/

void trav(int i, int currSum, vector<int> &currList, unordered_map<int, int> &map, vector<vector<int>> &ans, vector<int> &A, int &B) {
    if (currSum == B) { // if currSum == target
        ans.push_back(currList); // store ans
        return;
    }
    if (i >= A.size()) return; // out of bound
    
    int element = A[i];
    int totalCount = map[element];
    int usedCount = 0;
    
    // Add elements till target is reached and count is left
    while (currSum + element <= B && usedCount < totalCount) {
        currSum += element;
        currList.push_back(element);
        usedCount++;
    }
    
    // traverse and pop for each element
    while (usedCount > 0) {
        trav(i+1, currSum, currList, map, ans, A, B);
        currSum -= element;
        currList.pop_back();
        usedCount--;
    }
    
    // traverse without this element at all
    trav(i+1, currSum, currList, map, ans, A, B);    
}

vector<vector<int>> Solution::combinationSum(vector<int> &A, int B) {
    unordered_map<int, int> map;
    for (auto &a: A) map[a]++;
    
    A.clear();
    for (auto &m: map) A.push_back(m.first);
    sort(A.begin(), A.end());
    
    int currSum;
    vector<int> currList;
    vector<vector<int>> ans;
    
    trav(0, currSum, currList, map, ans, A, B);
    return ans;
}
