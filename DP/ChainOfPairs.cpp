// https://www.interviewbit.com/problems/chain-of-pairs/

int Solution::solve(vector<vector<int> > &A) {
    int N = A.size(), ret = 1;
    vector<int> dp(N, 1);
    
    for (int i=1; i<N; i++) {
        for (int j=0; j<i; j++) {
            if(A[j][1] < A[i][0]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ret = max(ret, dp[i]);
    }
    return ret;
}