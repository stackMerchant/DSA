// https://www.interviewbit.com/problems/dice-throw/

// Solution 1
// Time complexity = dices * faces * sum, so gives TLE

long findWays(int dices, int sum, int &faces, vector<vector<long>> &dp) {
    if (sum == 0 && dices == 0) return 1; // found
    if (sum <= 0 || dices == 0) return 0; // dices or sum exhausted
    
    if (dp[dices][sum] != -1) return dp[dices][sum];
    
    long ways = 0, mod = 1e9 + 7;
    for (int i=1; i<=faces; i++) { // iterate over all faces
        ways = (ways + findWays(dices - 1, sum - i, faces, dp)) % mod; // calculate for rest of the dices
    }
    dp[dices][sum] = ways;
    return dp[dices][sum];
}

int Solution::findDiceSum(int dices, int faces, int sum) {
    vector<vector<long>> dp(dices + 1, vector<long>(sum+1, -1));
    return findWays(dices, sum, faces, dp);
}


// Solution 2, Amazing approach
//
// Time complexity = dices * sum
// To understand,
// 1. think what dp[i][j] represents, and then
// 2. overlap of values between dp[i][j] from dp[i][j-1], and then
// 3. how can we get dp[i][j] from dp[i][j-1]

int Solution::findDiceSum(int dices, int faces, int sum) {
    vector<vector<int>> dp(dices+1, vector<int>(sum+1, 0));
    dp[0][0] = 1;
    int mod = 1e9 + 7;
    
    for (int i=1; i<=dices; i++) {
        for (int j=1; j<=sum; j++) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % mod;
            
            if (j-faces-1 >= 0) {
                dp[i][j] = (dp[i][j] - dp[i-1][j-faces-1] + mod) % mod;
            }
        }
    }
    return dp[dices][sum];
}
