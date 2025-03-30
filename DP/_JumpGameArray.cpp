// https://www.interviewbit.com/problems/jump-game-array/

// Can be optimized more
int Solution::canJump(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n, 0);
    dp[0] = 1;
    
    for (int i=0; i<n; i++) {
        if (dp[i] == 1) {
            for (int j=i+1; j<=i+A[i] && j<n; j++) {
                dp[j] = 1;
            }
        }
    }
    
    return dp[n-1];
}