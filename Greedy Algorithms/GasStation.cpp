// https://www.interviewbit.com/problems/gas-station/

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int start = 0, gas = 0, totalDiff = 0, currDiff;
    
    for (int i=0; i<n; i++) {
        currDiff = A[i] - B[i];
        totalDiff += currDiff;
        gas += currDiff;
        if (gas < 0) {
            start = (i+1) % n;
            gas = 0;
        }
    }
    
    return totalDiff >= 0 ? start : -1;
}
