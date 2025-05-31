// https://www.interviewbit.com/problems/coins-in-a-line/

int find(vector<int> &A, int a, int b, vector<vector<int>> &dp) {
    if (a > b) return 0;
    if (dp[a][b] != -1) return dp[a][b];
    
    int takeA = A[a] + min(find(A, a+2, b, dp), find(A, a+1, b-1, dp));
    int takeB = A[b] + min(find(A, a+1, b-1, dp), find(A, a, b-2, dp));
    dp[a][b] = max(takeA, takeB);
    return dp[a][b];
}

int Solution::maxcoin(vector<int> &A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return find(A, 0, n-1, dp);
}
