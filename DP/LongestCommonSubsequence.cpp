// https://www.interviewbit.com/problems/longest-common-subsequence/

int Solution::solve(string A, string B) {
    int na = A.size(), nb = B.size();
    vector<vector<int>> dp(na+1, vector<int>(nb+1, 0));
    
    for (int i=1; i<=na; i++) {
        for (int j=1; j<=nb; j++) {
            if(A[i-1] == B[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    return dp[na][nb];
}