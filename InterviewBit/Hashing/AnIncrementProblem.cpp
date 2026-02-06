// https://www.interviewbit.com/problems/an-increment-problem/

vector<int> Solution::solve(vector<int> &A) {
    for (int i=0; i<A.size(); i++) {
        for (int j=0; j<i; j++) {
            if (A[j] == A[i]) {
                A[j]++;
                break;
            }
        }
    }
    return A;
}
