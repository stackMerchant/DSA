// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stock-atmost-b-times/

// Solution 1

int Solution::solve(vector<int> &A, int B) {
    int m = A.size();
    if (B > m) B = m; // distraction, just reduce B
    
    int sellToday, doNothingToday, maxBuy;
    vector<vector<int>> dp(B+1, vector<int>(m, 0));
    for (int i=1; i<=B; i++) { // for each transaction
        maxBuy = INT_MIN; // what maximum a prev day could contribute, if bought on that day
        for (int j=1; j<m; j++) {
            maxBuy = max(maxBuy, -A[j-1] + dp[i-1][j-1]); // all before j-1 are already in maxPrev
            sellToday = A[j] + maxBuy;
            doNothingToday = dp[i][j-1];
            dp[i][j] = max(sellToday, doNothingToday);
        }
    }
    return dp[B][m-1];
}

// Solution 2, do recursive, will have 3D DP maybe