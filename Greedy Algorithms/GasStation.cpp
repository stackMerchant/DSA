// https://www.interviewbit.com/problems/gas-station/

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int diffs = 0, N = A.size(), minIndex = 0, sum = 0;
    
    for (int i=0; i<N; i++) {
        diffs += A[i] - B[i];
        sum += A[i] - B[i];
        if (sum < 0) {
            sum = 0;
            minIndex = i+1;
        }
    }
    
    if (diffs < 0) return -1;
    return minIndex % N;
}
