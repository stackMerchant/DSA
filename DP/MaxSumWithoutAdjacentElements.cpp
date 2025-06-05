// https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int> arr(n);
    for(int i=0; i<n; i++) arr[i] = max(A[0][i], A[1][i]);
    
    if (n == 1) return arr[0];
    
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    
    for (int i=2; i<n; i++)
        dp[i] = max(dp[i-2] + arr[i], dp[i-1]);
        
    return dp[n-1];
}
