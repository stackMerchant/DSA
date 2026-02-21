// https://www.interviewbit.com/problems/subset-sum-problem/

int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(B+1, false));
    
    for (int i=0; i<=n; i++) dp[i][0] = true;
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=B; j++) {
            bool notTake = dp[i-1][j];
            bool take = j - A[i-1] >= 0 && dp[i-1][j - A[i-1]];
            
            dp[i][j] = take || notTake;
        }
    }
    
    return dp[n][B];
}
