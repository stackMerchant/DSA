// https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &A, int B) {
    int l = 0, h = A.size() - 1, mid, minIdx = 0;
    
    while (l <= h) {
        mid = (h + l) / 2;
        if (A[mid] < A[minIdx]) {
            minIdx = mid;
            h = mid - 1;
        } else l = mid + 1;
    }
    
    int id1 = lower_bound(A.begin(), A.begin() + minIdx - 1, B) - A.begin();
    int id2 = lower_bound(A.begin() + minIdx, A.end(), B) - A.begin();
    
    if (A[id1] == B) return id1;
    if (A[id2] == B) return id2;
    return -1;
}
