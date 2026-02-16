// https://www.interviewbit.com/problems/different-bits-sum-pairwise/

int Solution::cntBits(vector<int> &A) {
    long long int sum = 0, mod = pow(10, 9) + 7, N = A.size(), nZero, nOne, mask;
    
    for (int i=0; i<=31; i++) {
        mask = 1 << i;
        nZero = 0; nOne = 0;
        for (int j = 0; j<N; j++)
            if ((A[j] & mask)) nOne++; else nZero++;
            
        sum = (sum + (2 * nZero * nOne) % mod) % mod;
    }
    return sum;
}
