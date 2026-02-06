// https://www.interviewbit.com/problems/longest-subarray-length/

int Solution::solve(vector<int> &A) {
    unordered_map<int, int> sumToIndex;
    
    int n = A.size(), ret = 0, currSum = 0;
    for (int i=0; i<n; i++) {
        currSum += A[i] == 1 ? 1 : -1; // calculate prefix sum
        
        if (currSum == 1) // if currSum is target
            ret = max(ret, i+1); // count all elements
        else if (sumToIndex.find(currSum - 1) != sumToIndex.end()) // find first occurence of currSum - target
            ret = max(ret, i - sumToIndex[currSum - 1]);
        
        if (sumToIndex.find(currSum) == sumToIndex.end()) // add currSum to map
            sumToIndex[currSum] = i;
    }
    return ret;
}
