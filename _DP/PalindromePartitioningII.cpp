// https://www.interviewbit.com/problems/palindrome-partitioning-ii/

// Solution 1 => 2D array

bool isPalindrome(string A, int a, int b) {
    for (int i=a; i<=b; i++) if (A[i] != A[a+b-i]) return false;
    return true;
}

int Solution::minCut(string A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    
    for (int l = 0; l<n; l++) { // Will determine the length of string we are considering
        for (int i=0; i+l < n; i++) { // Start of string (inclusive)
            int j = i + l; // End of string (inclusive)
            if (isPalindrome(A, i, j)) dp[i][j] = 0; // If palindrome then no cuts
            else { // Cut all in between and take minimum
                for (int k=i; k<j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + 1);
            }
        }
    }
    return dp[0][n-1];
}

// Solution 2 => Rec + memo, giving TLE

int findCuts(string A, int a, int b, vector<vector<int>> &dp) {
    if (dp[a][b] != -1) return dp[a][b];

    if (isPalindrome(A, a, b)) {
        dp[a][b] = 0;
        return dp[a][b];
    }
    
    int minCuts = INT_MAX, currCuts;
    for (int i=a; i<b; i++) {
        currCuts = findCuts(A, a, i, dp) + findCuts(A, i+1, b, dp) + 1;
        minCuts = min(minCuts, currCuts);
    }

    dp[a][b] = minCuts;
    return dp[a][b];
}

int Solution::minCut(string A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return findCuts(A, 0, n-1, dp);
}
