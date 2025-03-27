// https://www.interviewbit.com/problems/assign-mice-to-holes/

int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int N = A.size(), ret = 0;
    for(int i=0; i<N; i++) {
        ret = max(ret, abs(A[i] - B[i]));
    }
    return ret;
}
