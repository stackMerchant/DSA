// https://www.interviewbit.com/problems/regular-expression-match/

// Do regex questions with 2D table

// Solution 1 => With bool matrix

int Solution::isMatch(string A, string B) {
    int a = A.size(), b = B.size();
    vector<vector<bool>> dp(a+1, vector<bool>(b+1, false));
    
    dp[0][0] = true; // If both strings are consumed
    for (int j=1; j<=b; j++) if (B[j-1] == '*') dp[0][j] = dp[0][j-1]; // If B matches with empty string A
    
    for (int i=1; i<=a; i++) {
        for (int j=1; j<=b; j++) {
            if (A[i-1] == B[j-1] || B[j-1] == '?') // If chars match
                dp[i][j] = dp[i-1][j-1];
            else if (B[j-1] == '*')
                // Match * with 0 char from A
                // Match * with multiple char from A, so remove one from A and preserve * in B
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
        }
    }
    
    return dp[a][b];
}

// Solution 2 => With recursion and memo, but getting TLE
//   Because of int matrix, and we can't do bool matrix with rec+memo

int check(string &A, string &B, int a, int b, vector<vector<int>> &dp) {
    if (dp[a][b] != -1) return dp[a][b]; // If already calculated

    if (a == 0 && b == 0) // If both consumed
        dp[a][b] = 1;
    else if (a == 0 && B[b-1] == '*') // If A is consumed, but B remains with *
        dp[a][b] = check(A, B, a, b-1, dp);
    else if (a == 0 || b == 0) // If only one of the strings are consumed
        dp[a][b] = 0;
    else if (A[a-1] == B[b-1] || B[b-1] == '?') // If front chars match
        dp[a][b] = check(A, B, a-1, b-1, dp);
    else if (B[b-1] == '*') {
        // int c1 = check(A, B, a, b-1, dp); // Match * with 0 char from A
        // int c2 = check(A, B, a-1, b, dp); // Match * with multiple char from A, so remove one from A and preserve * in B
        dp[a][b] = check(A, B, a, b-1, dp) | check(A, B, a-1, b, dp);
    } else dp[a][b] = 0;

    return dp[a][b];
}

int Solution::isMatch(string A, string B) {
    int a = A.size(), b = B.size();
    vector<vector<int>> dp(a+1, vector<int>(b+1, -1));
    return check(A, B, a, b, dp);
}