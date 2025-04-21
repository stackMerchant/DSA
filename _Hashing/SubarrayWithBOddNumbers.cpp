// https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/

/************ Solution 1 ************/

int Solution::solve(vector<int> &A, int B) {
    // Save the number of even elements on left of each odd element, including self
    vector<int> onLeft(N, 0);
    int oddTill = 0;
    
    int ret = 0;
    for (auto a: A) {
        onLeft[oddTill]++;
        if(a & 1) oddTill++;
        if(oddTill >= B) count += onLeft[oddTill - B];
    }
    return ret;
}

/************ Solution 2 ************/

int Solution::solve(vector<int> &A, int B) {
    
    int N = A.size();
    vector<int> evenLeft, evenRight;
    
    int evenTill = 0;
    for(int i=0; i<N; i++) {
        if(A[i] & 1) {
            evenLeft.push_back(evenTill);
            evenTill = 0;
        }
        else evenTill++;
    }
    
    evenTill = 0;
    for(int i=N-1; i>=0; i--) {
        if(A[i] & 1) {
            evenRight.push_back(evenTill);
            evenTill = 0;
        }
        else evenTill++;
    }
    reverse(evenRight.begin(), evenRight.end());
    
    int count = 0;
    if(B==0) { // NOTE: B = 0
        if(evenLeft.size() == 0) {
            return pow(2, N) - 1; // NOTE: No odd number present
        }
        
        for (int i=0; i < evenLeft.size(); i++) {
            count += pow(2, evenLeft[i]) - 1;
        }
        count += pow(2, evenRight.back()) - 1;
    } else {
        for (int i=0; i+B-1 < evenLeft.size(); i++) {
            count += (evenLeft[i]+1)*(evenRight[i+B-1]+1);
        }
    }
    return count;
}