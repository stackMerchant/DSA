// https://www.interviewbit.com/problems/minimum-difference-subsets/

int Solution::solve(vector<int> &A) {
    int sum = 0;
    for (auto &a: A) sum += a;
    
    int n = A.size(), halfSum = sum/2, maxHalfSum = 0; // find only till half
    vector<vector<bool>> dp(n+1, vector<bool>(halfSum+1, false));
    
    for (int i=0; i<=n; i++) dp[i][0] = true;
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=halfSum; j++) {
            bool notTake = dp[i-1][j];
            bool take = j - A[i-1] >=0 && dp[i-1][j - A[i-1]];
            dp[i][j] = notTake || take;
            
            if (dp[i][j]) maxHalfSum = max(maxHalfSum, j); // save max half sum
        }
    }
    
    return sum - 2 * maxHalfSum;
}
