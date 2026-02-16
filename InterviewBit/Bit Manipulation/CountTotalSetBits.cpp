// https://www.interviewbit.com/problems/count-total-set-bits/

#define ll long long int

int Solution::solve(int A) {
    if (A == 0) return 0;
    ll mod = 1e9 + 7;
    
    ll po2 = 1;
    ll i = 0;
    while (A >= 2 * po2) {
        po2 *= 2;
        i += 1;        
    }
    
    ll tillPo2 = ((po2 * i) / 2) % mod; // till power of 2, 0-1 are half-half
    ll fromPo2 = solve(A - po2) % mod; // same applies for numbers after power of 2
    ll mostSig = (A - po2 + 1) % mod; // count most significant bit separately
    
    return (mostSig + fromPo2 + tillPo2) % mod;
}
