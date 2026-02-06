// https://www.interviewbit.com/problems/subarray-with-b-odd-numbers/

/************ Solution 1 ************/

int Solution::solve(vector<int> &A, int B) {
    // Partition by odds, and save length of each partition
    vector<int> evens;
    int evenTill = 0;
    for (auto &a: A) {
        if (a % 2 == 1) {
            evens.push_back(evenTill);
            evenTill = 0;
        } else evenTill++;
    }
    evens.push_back(evenTill);
    
    // If no odd should be taken, then all subarrays of all partitions
    int ret = 0;
    if (B == 0) {
        for (auto &e: evens)
            ret += (e*(e+1)) / 2; // Number of subarrays, by 1 + 2 + ... + n
        return ret;
    }
    
    // Sigma over (partition1 + 1) * (partition2 + 1)
    for (int i=0; i + B < evens.size(); i++)
        ret += (evens[i] + 1) * (evens[i + B] + 1);
    
    return ret;
}

/************ Solution 2 ************/

// Not endorsed

int Solution::solve(vector<int> &A, int B) {
    // Save the number of even elements on left of each odd element, including self
    vector<int> onLeft(A.size(), 0);
    int oddTill = 0;
    
    int ret = 0;
    for (auto a: A) {
        onLeft[oddTill]++;
        if(a & 1) oddTill++;
        if(oddTill >= B) count += onLeft[oddTill - B];
    }
    return ret;
}