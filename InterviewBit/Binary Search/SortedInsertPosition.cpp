// https://www.interviewbit.com/problems/sorted-insert-position/

int Solution::searchInsert(vector<int> &A, int B) {
    // return lower_bound(A.begin(), A.end(), B) - A.begin();
    
    int low = 0, high = A.size(), mid, ans = 0;
    while (low <= high) {
        mid = (high + low) / 2;
        if (A[mid] >= B) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}
