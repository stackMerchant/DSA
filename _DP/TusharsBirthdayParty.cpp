// https://www.interviewbit.com/problems/tushars-birthday-party/

int getCost(vector<int> &dp, vector<int> dishes, vector<int> costs, int capacity) {
    if (capacity <= 0) return 0;
    if (dp[capacity] != -1) return dp[capacity];
    
    int n = dishes.size(), minCost = -1, stepCost;
    
    for (int i=0; i<n; i++) {
        if (dishes[i] <= capacity) {
            stepCost = costs[i] + getCost(dp, dishes, costs, capacity - dishes[i]);
            
            if (minCost == -1) minCost = stepCost;
            else minCost = min(minCost, stepCost);
        }
    }
    
    dp[capacity] = minCost;
    return dp[capacity];
}

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    // Get the highest capacity
    int maxCapacity = 0;
    for (int a: A) maxCapacity = max(maxCapacity, a);
    
    // Store cost at each capacity less than maxCapacity
    vector<int> dp(maxCapacity + 1, -1);
    getCost(dp, B, C, maxCapacity);
    
    // Query all and add costs
    int ret = 0;
    for (int a: A) ret += dp[a];
    return ret;
}
