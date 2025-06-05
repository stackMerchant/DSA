// https://www.interviewbit.com/problems/stairs/

// Write a better clearer solution
int getWays(vector<int> &dp, int A) {
    if (A<1) return 0;
    if (A==1) return 1;
    if (dp[A] != -1) return dp[A];

    dp[A] = getWays(dp, A-1) + getWays(dp, A-2);
    return dp[A];
}

int Solution::climbStairs(int A) {
    vector<int> dp(A+2, -1);
    return getWays(dp, A+1);
}
