// https://www.interviewbit.com/problems/interleaving-strings/

// Solution 1 => Recursion and memo

// a, b & c are number of elements to be taken from A, B & C
int check(string A, string B, string C, int a, int b, vector<vector<int>> &dp) {
    if (dp[a][b] != -1) return dp[a][b]; // If already calculated
    
    int c = a + b;
    if (c == 0) // If all of C is constructed
        dp[a][b] = 1;
    else if (a > 0 && C[c-1] == A[a-1] && check(A, B, C, a-1, b, dp)) // If front chars of C and A match
        dp[a][b] = 1;
    else if (b > 0 && C[c-1] == B[b-1] && check(A, B, C, a, b-1, dp)) // If front chars of C and B match
        dp[a][b] = 1;
    else
        dp[a][b] = 0;
    
    return dp[a][b];
}

int Solution::isInterleave(string A, string B, string C) {
    int a = A.size(), b = B.size();;
    vector<vector<int>> dp(a+1, vector<int>(b+1, -1));
    return check(A, B, C, a, b, dp);
}

// Think about if a + b > c (Solution => just add one more condition)

// Solution 2 => With matrix

int Solution::isInterleave(string A, string B, string C){
    int a = A.size(), b = B.size();
    vector<vector<int>> dp(a+1, vector<int>(b+1, 0));
    
    for (int i=0; i<=a; i++) {
        for (int j=0; j<=b; j++) {
            int k = i+j;
            if (i==0 && j==0)
                dp[i][j] = 1;
            else if (i>0 && j>0 && A[i-1]==C[k-1] && B[j-1]==C[k-1])
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
            else if (j>0 && B[j-1] == C[k-1])
                dp[i][j] = dp[i][j-1];
            else if (i>0 && A[i-1] == C[k-1])
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[a][b];
}