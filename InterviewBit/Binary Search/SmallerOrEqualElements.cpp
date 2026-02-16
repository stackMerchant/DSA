// https://www.interviewbit.com/problems/smaller-or-equal-elements/

int Solution::solve(vector<int> &A, int B) {
int low = 0, high = A.size() - 1, mid, ans = 0;
    while (low <= high) {
        mid = (high + low) / 2;
        
        if (A[mid] <= B) {
            ans = mid + 1;
            low = mid + 1;
        } else high = mid - 1;
    }
    return ans;
}
