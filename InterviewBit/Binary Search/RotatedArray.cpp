// https://www.interviewbit.com/problems/rotated-array/

int Solution::findMin(const vector<int> &A) {
    int n = A.size();
    int low = 0, high = n-1, index = 0, mid; // index of a small number
    while (low <= high) {
        mid = (low + high) / 2;
        if (A[mid] < A[index]) {
            index = mid;
            high = mid-1;
        } else low = mid+1;
    }
    return A[index];
}
