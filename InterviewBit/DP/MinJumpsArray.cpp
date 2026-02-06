// https://www.interviewbit.com/problems/min-jumps-array/

// Solution 1, O(n)
// The idea to keep track of max visitable index with step + 1, till max visitable index with step is reached

int Solution::jump(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n, 0);
    int lastMax = A[0], nextMax;
    int steps = 0;
    
    int i=1;
    for (; i < n && i <= lastMax; ) {
        steps++;
        nextMax = i;
        while (i < n && i <= lastMax) {
            nextMax = max(nextMax, i + A[i]);
            i++;
        }
        lastMax = nextMax;
    }
    
    return i == n ? steps : -1;
}

// Solution 2, O(n^2)

// Kinda brute force

// Write clear and better
int Solution::jump(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    // if a bigger number is already processed, don't process small numbers ahead
    int check = -1;
    
    for (int i=0; i<n; i++) {
        if (dp[i] != -1 && A[i] > check) {
            check = A[i];
            for (int j=i+1; j<=i+A[i] && j<n; j++) {
                if (dp[j] == -1) dp[j] = dp[i] + 1;
                else dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        check--;
    }
    
    return dp[n-1];
}
