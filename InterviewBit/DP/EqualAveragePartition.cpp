// https://www.interviewbit.com/problems/equal-average-partition/

bool trav(int idx, int leftSize, int leftSum, vector<int> &A, vector<int> &takeList, vector<vector<vector<int>>> &dp) {
    if (leftSize == 0 && leftSum == 0) return true; // target size and target sum achieved
    if (idx >= A.size() || leftSize <= 0 || leftSum <= 0) return false; // out of bound params
    
    if (dp[idx][leftSum][leftSize] != -1) return false; // if already calculated
    
    // with idx element
    takeList.push_back(A[idx]);
    if (trav(idx + 1, leftSize - 1, leftSum - A[idx], A, takeList, dp)) return true;
    takeList.pop_back();
    
    // without idx element
    if (trav(idx + 1, leftSize, leftSum, A, takeList, dp)) return true;
    
    dp[idx][leftSum][leftSize] = 0; // this combination of params are not working out
    return false;
}

vector<vector<int> > Solution::avgset(vector<int> &A) {
    sort(A.begin(), A.end());
    
    int n = A.size(), sum = 0;
    for (auto a: A) sum += a;
    
    vector<int> takeList(0), dropList(0);
    
    for (int i=1; i<n; i++) {
        if ((sum * i) % n != 0) continue; // find target size and target sum using a1/a2 = b1/b2 = (a1+b1)/(a2+b2)
        int targetSum = (sum * i) / n;

        // traverse to find which elements to pick, with a 3D dp to store combinations that will not work out
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(targetSum + 1, vector<int>(i+1, -1)));
        if (trav(0, i, targetSum, A, takeList, dp)) break;
    }
    
    // we have takeList now, prepare dropList from it, use map because n(element) can be > 1
    
    vector<vector<int>> ans;
    if (takeList.size() == 0) return ans;
    
    unordered_map<int, int> takeMap;
    for (auto a: takeList) {
        if (takeMap.find(a) == takeMap.end()) takeMap[a] = 1;
        else takeMap[a]++;
    }
    
    for (auto a: A) {
        if (takeMap.find(a) == takeMap.end()) dropList.push_back(a);
        else if (takeMap[a] == 1) takeMap.erase(a);
        else takeMap[a]--;
    }
    
    ans.push_back(takeList);
    ans.push_back(dropList);
    return ans;
}
