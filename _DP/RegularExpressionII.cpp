// https://www.interviewbit.com/problems/regular-expression-ii/

// Do regex questions with 2D table

// Solution 1 => With 2D table

int Solution::isMatch(string A, string B) {    
    int a = A.size(), b = B.size();
    vector<vector<bool>> dp(a+1, vector<bool>(b+1, false));
    
    dp[0][0] = true; // If both strings are consumed
    for (int j=1; j<=b; j++) if (B[j-1] == '*') dp[0][j] = dp[0][j-2]; // If B matches with empty string A
    
    for (int i=1; i<=a; i++) {
        for (int j=1; j<=b; j++) {
            if (B[j-1] == '.' || A[i-1] == B[j-1]) // If chars match
                dp[i][j] = dp[i-1][j-1];
            else if (B[j-1] == '*') {
                if (dp[i][j-2]) // Match _* with 0 char from A
                    dp[i][j] = true;
                else if (B[j-2] == '.' || A[i-1] == B[j-2]) // Match _* with multiple char from A, so remove one from A and preserve _* in B
                    dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[a][b];
}

// Solution 2 => Recursion with memo

int trav(string A, string B, int a, int b, vector<vector<int>> &dp) {
    if (dp[a][b] != -1) return dp[a][b];
    
    if (a == 0 && b == 0) // Both strings consumed
        dp[a][b] = 1;
    else if (a == 0 && b > 0) {
        if (B[b-1] == '*') dp[a][b] = trav(A, B, a, b-2, dp);
        else dp[a][b] = 0;
    }
    else if (a > 0 && b == 0)
        dp[a][b] = 0;
    else if (A[a-1] == B[b-1] || B[b-1] == '.')
        dp[a][b] = trav(A, B, a-1, b-1, dp);
    else if (B[b-1] == '*') {
        if (trav(A, B, a, b-2, dp)) // Make _* match with empty char in a
            dp[a][b] = true;
        else if (A[a-1] == B[b-2] || B[b-2] == '.')
            dp[a][b] = trav(A, B, a-1, b, dp);
        else dp[a][b] = 0;
    } else dp[a][b] = 0;
    
    return dp[a][b];
}

int Solution::isMatch(string A, string B) {
    int a = A.size(), b = B.size();
    vector<vector<int>> dp(a+1, vector<int>(b+1, -1));
    return trav(A, B, a, b, dp);    
}