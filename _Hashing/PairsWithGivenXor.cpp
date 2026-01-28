// https://www.interviewbit.com/problems/pairs-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    int N = A.size();
    unordered_set<int> s;
    int count = 0;
    
    for (int i=0; i<N; i++) {
        if(s.find(A[i]) == s.end()) {
            s.insert(A[i]^B);
        } else {
            count++;
        }
    }
    return count;
}

// In above question, elements are distinct, if not distinct, maintain 2 maps
// Map 1, processed for insertion
// Map 2, processed for answer
// Or figure out with only one map