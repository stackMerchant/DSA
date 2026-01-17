// https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/

// Soution 1, using dp table

int Solution::chordCnt(int A) {
    if (A==0 || A==1) return 1;
    
    int mod = pow(10, 9)+7;
    vector<long long int> ways(A+1, 0);
    ways[0] = 1; ways[1] = 1;
    
    for (int i=2; i<=A; i++)
        for (int j=0; j<i; j++)
            ways[i] = (ways[i] + (ways[j] * ways[i-1-j]) % mod) % mod;

    return ways.back();
}

// Solution 2, using recursion + memo

typedef long long ll;

ll calc (int A, vector<ll> &dp) {
    if (dp[A] != -1) return dp[A];
    ll mod = 1e9+ 7;
    
    ll ret = 0, mul;
    for (int i=0; i<A; i++) {
        mul = (calc(i, dp) * calc(A-i-1, dp)) % mod;
        ret = (ret + mul) % mod;
    }
    dp[A] = ret;
    return dp[A];
}

int Solution::chordCnt(int A) {
    vector<ll> dp(A+1, -1);
    dp[0] = 1; dp[1] = 1;
    calc(A, dp);
    return dp[A];
}
