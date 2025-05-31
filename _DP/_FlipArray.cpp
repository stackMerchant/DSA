// https://www.interviewbit.com/problems/flip-array/

// Find out how it is a knapsack, and write a knapsack too

int Solution::solve(const vector<int> &A) {
    int sum = 0;
    for (auto a: A) sum += a;
    sum /= 2;
    
    // This will help determine, min elements required to reach a sum
    vector<int> dp(sum + 1, INT_MAX); dp[0] = 0;
    
    for (int i=0; i<A.size(); i++) {
        for (int j=sum; j-A[i] >= 0; j--) {
            if (dp[j-A[i]] != INT_MAX)
                dp[j] = min(dp[j], dp[j - A[i]] + 1);
        }
    }
    
    for (int i=sum; i>=0; i--)
        if (dp[i] != INT_MAX) return dp[i];
}