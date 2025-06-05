// https://www.interviewbit.com/problems/0-1-knapsack/

int getValue(vector<vector<int>> &dp, vector<int> values, vector<int> weights, int i, int weightLimit) {
    if (i < 0 || weightLimit <= 0) return 0;
    
    if (dp[i][weightLimit] != -1) return dp[i][weightLimit];
    
    // Calculate value if i item is not picked
    int notTakeValue = getValue(dp, values, weights, i-1, weightLimit);
    
    // Calculate value if i item is picked
    int takeValue = 0;
    int weightLeft = weightLimit - weights[i];
    if (weightLeft >= 0) {
        takeValue = values[i] + getValue(dp, values, weights, i-1, weightLeft);
    }
    
    dp[i][weightLimit] = max(takeValue, notTakeValue);
    return dp[i][weightLimit];
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int N = A.size();
    vector<vector<int>> dp = vector<vector<int>>(N, vector<int>(C+1, -1));
    return getValue(dp, A, B, N-1, C);
}