// https://www.interviewbit.com/problems/first-repeating-element/

int Solution::solve(vector<int> &A) {
    int N = A.size();
    unordered_set<int> s;
    int lastDup = -1;
    
    for(int i=N-1; i>=0; i--) {
        if(s.find(A[i]) == s.end()) {
            s.insert(A[i]);
        } else {
            lastDup = A[i];
        }
    }
    return lastDup;
}
