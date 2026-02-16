// https://www.interviewbit.com/problems/count-element-occurence/

// Solution 1

int findFirst(const vector<int> &A, int low, int high, int target) {
    if (low > high) return -1;
    
    int mid = low + (high - low) / 2;
    if(A[mid] == target)  {
        int earlier = findFirst(A, low, mid-1, target);
        return earlier == -1 ? mid : earlier;
    }
    if (A[mid] < target) return findFirst(A, mid+1, high, target);
    return findFirst(A, low, mid-1, target);
}

int findLast(const vector<int> &A, int low, int high, int target) {
    if(low > high) return -1;
    
    int mid = low + (high - low) / 2;
    if(A[mid] == target)  {
        int later = findLast(A, mid+1, high, target);
        return later == -1 ? mid : later;
    }
    
    if (A[mid] < target) return findLast(A, mid+1, high, target);
    return findLast(A, low, mid-1, target);
}

int Solution::findCount(const vector<int> &A, int B) {
    int first = findFirst(A, 0, A.size()-1, B);
    int last = findLast(A, 0, A.size()-1, B);
    if (first == -1) return 0;
    return last - first + 1;    
}

// Solution 2

int Solution::findCount(const vector<int> &A, int B) {
    int st = lower_bound(A.begin(), A.end(), B) - A.begin();
    int ed = upper_bound(A.begin(), A.end(), B) - A.begin();
    return ed-st;   
}
