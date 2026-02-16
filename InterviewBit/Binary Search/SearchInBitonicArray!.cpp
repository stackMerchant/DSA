// https://www.interviewbit.com/problems/search-in-bitonic-array/

int Solution::solve(vector<int> &A, int B) {
    int low, high, mid, maxInd = 0, curr, prev, next, target, n = A.size();
    bool isInc;
    
    // Find maxInd to split by maxInd
    low = 0; high = n - 1;
    while (low <= high) {
        mid = (high + low) / 2;
        
        curr = A[mid];
        prev = mid - 1 >=0 ? A[mid - 1] : -1;
        next = mid + 1 < n ? A[mid + 1] : -1;
        
        if (curr > prev && curr > next) {
            maxInd = mid;
            break;
        }
        
        isInc = prev < curr && curr < next;
        if (isInc) low = mid + 1; else high = mid - 1;
    }
    
    // Search in first half
    low = 0; high = maxInd; target = B;
    while (low <= high) {
        mid = (high + low) / 2;
        if (A[mid] == target) return mid;
        if (A[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    
    // Search in second half
    low = maxInd; high = n - 1; target = B;
    while (low <= high) {
        mid = (high + low) / 2;
        if (A[mid] == target) return mid;
        if (A[mid] > target) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}
