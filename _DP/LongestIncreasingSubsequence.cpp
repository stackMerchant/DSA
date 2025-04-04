// https://www.interviewbit.com/problems/longest-increasing-subsequence/

int Solution::lis(const vector<int> &A) {
    int n = A.size(), ret = 1;
    vector<int> yet(n, 1);
    
    for (int i = 1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (A[j] < A[i]) {
                yet[i] = max(yet[i], yet[j] + 1);
                ret = max(ret, yet[i]);
            }
        }
    }
    
    return ret;
}