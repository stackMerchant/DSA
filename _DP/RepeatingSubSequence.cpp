// https://www.interviewbit.com/problems/repeating-subsequence/

int find(string &A, int i, int j, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    
    // Without comparing elements at i and j
    dp[i][j] = max(find(A, i-1, j, dp), find(A, i, j-1, dp));
    // If elements at i and j are same
    if (i != j && A[i] == A[j]) dp[i][j] = max(dp[i][j], 1 + find(A, i-1, j-1, dp));
    return dp[i][j];
}

int Solution::anytwo(string A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return find(A, n-1, n-1, dp) >= 2;
}