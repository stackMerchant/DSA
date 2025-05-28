// https://www.interviewbit.com/problems/distinct-subsequences/

// Solution 1 => Using recursion with memoization

// a and b are indexes of A and B
int trav(string &A, string &B, int a, int b, vector<vector<int>> &dp) { 
    // If b is consumed, word was created
    if (b < 0) return 1;
    // If a is consumed, or is less than b no combination possible
    //  because then we won't have enough chars in a to make b
    if (a < 0 || a < b) return 0;
    
    // If already calculated
    if (dp[a][b] != -1) return dp[a][b];
    
    dp[a][b] = trav(A, B, a-1, b, dp); // Without considering A[a]
    if (A[a] == B[b]) dp[a][b] += trav(A, B, a-1, b-1, dp); // Considering A[a]
    return dp[a][b];
}

int Solution::numDistinct(string A, string B) {
    int a = A.size(), b = B.size();
    vector<vector<int>> dp(a, vector<int>(b, -1));
    return trav(A, B, a-1, b-1, dp);
}

// Solution 2 => Using 2D array

int Solution::numDistinct(string A, string B){
    int m = B.size(), n = A.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int j=0; j<=n; j++) dp[0][j] = 1;
    for (int i=1; i<=m; i++) {
        for(int j=1;j<=n;j++) {
            dp[i][j] += dp[i][j-1];
            if (B[i-1] == A[j-1]) dp[i][j] += dp[i-1][j-1];
        }
    }
    return dp[m][n];
}