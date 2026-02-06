// 1
// Tiling 2 X N space, with 2 X 1 dominoes
// f(n) = f(n-1) + f(n-2);

// 2
// Tiling 3 X N space, with 2 X 1 dominoes
// https://www.interviewbit.com/problems/tiling-with-dominoes/
// Formula:
// Start with dp[n] = 3 * dp[n-2] + 2 * (dp[n-4] + dp[n-6] + .......)  ---- (1)
// Then write for dp[n-2] and subtract from (1)
// You'll get dp[n] = 4 * dp[n-2] - dp[n-4]
// Take heed of mod in subtracting, add mod while subtracting

typedef long long ll;

int Solution::solve(int A) {
    // set up dp
    int len = max(A, 3) + 1;
    vector<ll> dp(len, 0);
    dp[0] = 1;
    dp[2] = 3;
    
    ll mod = 1e9 + 7;
    for (int i=4; i<len; i += 2) {
        // derived formula => dp[n] = 4 * dp[n-2] - dp[n-4]
        dp[i] = ((4 * dp[i-2]) % mod + mod - dp[i-4]) % mod;
    }
    return dp[A];
}

// 3
// Leetcode 790, domino and trimino
// f(n) = [2 * f(n-1)] + f(n-3)
// Reference: https://www.youtube.com/watch?v=o75alNvYqHU
