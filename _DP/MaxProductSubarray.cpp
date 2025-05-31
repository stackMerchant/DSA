// https://www.interviewbit.com/problems/max-product-subarray/

int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    if (n == 0) return 0;
    int maxTill = A[0], minTill = A[0], ret = A[0];
    
    for (int i=1; i<n; i++) {
        if (A[i] < 0) swap(maxTill, minTill);
        maxTill = max(A[i], maxTill * A[i]);
        minTill = min(A[i], minTill * A[i]);
        ret = max(ret, maxTill);
    }
    
    return ret;
}