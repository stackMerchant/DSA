// http://interviewbit.com/problems/min-xor-value/

int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    int ans = A[0]^A[1];
    for (int i=2; i<A.size(); i++) {
        ans = min(ans, A[i]^A[i-1]);
    }
    return ans;
}
