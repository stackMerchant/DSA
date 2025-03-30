// https://www.interviewbit.com/problems/longest-palindromic-subsequence/

/************ Solution 1 ************/
// Recursion with memoization

int trav(vector<vector<int>> &dp, string A, int i, int j) {
    if (i==j) return 1;
    if (i>j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (A[i] == A[j])
        dp[i][j] = 2 + trav(dp, A, i+1, j-1);
    else
        dp[i][j] = max(trav(dp, A, i+1, j), trav(dp, A, i, j-1));
    
    return dp[i][j];
}

int Solution::solve(string A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return trav(dp, A, 0, n-1);
}

/************ Solution 2 ************/
// By creating table

int Solution::solve(string A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i=0; i<n; i++) dp[i][i] = 1;
    
    for (int i=n-2; i>=0; i--)
        for (int j=i+1; j<n; j++)
            if (A[i] == A[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);

    return dp[0][n-1];
}

/************ Solution 3 ************/
// Reverse string and do LCS (Longest Common Subsequence)

int Solution::solve(string A) {
    string B = A;
    reverse(B.begin(), B.end());
    
    int na = A.size(), nb = B.size();
    vector<vector<int>> dp(na+1, vector<int>(nb+1, 0));
    
    for (int i=1; i<=na; i++)
        for (int j=1; j<=nb; j++)
            if(A[i-1] == B[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

    return dp[na][nb];
}
