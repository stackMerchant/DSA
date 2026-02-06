// https://www.interviewbit.com/problems/palindrome-partitioning/

// Solution 1
// Gets accepted, but might give TLE for larger cases as duplicate calculations

bool isPalindrome(string s) {
    int n = s.size();
    
    for (int i=0; i<n/2; i++)
        if (s[i] != s[n - i - 1]) 
            return false;

    return true;
}

void trav(int i, vector<string> &currList, string A, vector<vector<string>> &ans) {
    if (i == A.size()) {
        ans.push_back(currList);
        return;
    }
    
    string currString = "";
    for (int j=i; j<A.size(); j++) {
        currString += A[j];
        if (isPalindrome(currString)) {
            currList.push_back(currString);
            trav(j+1, currList, A, ans);
            currList.pop_back();
        }
    }
}

vector<vector<string>> Solution::partition(string A) {
    vector<vector<string>> ans;
    vector<string> currList;
    trav(0, currList, A, ans);
    return ans;
}

// Solution 2
// With DP

void trav(int i, string &A, vector<vector<vector<string>>> &dp) {
    if (dp[i].size() != 0) return;
    
    vector<vector<string>> fromI;
    string currString = "";
    for (int j=i; j<A.size(); j++) {
        currString += A[j];
        if (isPalindrome(currString)) {
            trav(j+1, A, dp);
            vector<vector<string>> afterJ = dp[j+1];
            
            for (auto &aj: afterJ) {
                aj.push_back(currString);
                fromI.push_back(aj);
            }
        }
    }
    dp[i] = fromI;
}

vector<vector<string>> Solution::partition(string A) {
    int n = A.size();
    vector<vector<vector<string>>> dp(n + 1);
    dp[n] = {{}};
    trav(0, A, dp);
    
    vector<vector<string>> ans = dp[0];
    
    for (auto &a: ans) reverse(a.begin(), a.end());
    return ans;
}
