// https://www.interviewbit.com/problems/n-digit-numbers-with-digit-sum-s-/

int mod = 1000000007;

int trav(int totalDigitsCount, int digitsCount, int sum, vector<vector<int>> &dp) {
    if (digitsCount == 0) return sum == 0;
    if (sum < 0) return 0;
    if (dp[digitsCount][sum] != -1) return dp[digitsCount][sum];
    
    int currSum = 0;
    for (int i=0; i<=9; i++) {
        if (!(i == 0 && totalDigitsCount == digitsCount)) {
            int rest = trav(totalDigitsCount, digitsCount - 1, sum - i, dp);
            currSum = (currSum + rest) % mod;
        }
    }
    dp[digitsCount][sum] = currSum;
    return dp[digitsCount][sum];
}

int Solution::solve(int digitsCount, int sum) {
    vector<vector<int>> dp(digitsCount+1, vector<int>(sum+1, -1));
    return trav(digitsCount, digitsCount, sum, dp);
}
