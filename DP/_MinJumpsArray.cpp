// https://www.interviewbit.com/problems/min-jumps-array/

// Write clear and better
int Solution::jump(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    // if a bigger number is already processed, don't process small numbers ahead
    int check = -1;
    
    for (int i=0; i<n; i++) {
        if (dp[i] != -1 && A[i] > check) {
            check = A[i];
            for (int j=i+1; j<=i+A[i] && j<n; j++) {
                if (dp[j] == -1) dp[j] = dp[i] + 1;
                else dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        check--;
    }
    
    return dp[n-1];
}
