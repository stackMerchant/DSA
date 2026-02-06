// https://www.interviewbit.com/problems/diffk-ii/

int Solution::diffPossible(const vector<int> &A, int B) {
    int N = A.size();
    unordered_set<int> s;
    
    for (int i=0; i<N; i++) {
        if (s.find(A[i]) != s.end()) {
            return 1;
        } else {
            s.insert(A[i] - B);
            s.insert(A[i] + B);
        }
    }
    return 0;
}
