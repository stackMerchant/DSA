// https://www.interviewbit.com/problems/interview-questions/

// Count all the state changes, assume one on bulb before first bulb

int Solution::bulbs(vector<int> &A) {
    int N = A.size(), ret = 0, curr = 1;
    for (int i=0; i<N; i++) {
        if (A[i] != curr) {
            ret++;
            curr = A[i];
        }
    }
    return ret;
}
