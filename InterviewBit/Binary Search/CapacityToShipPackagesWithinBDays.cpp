// https://www.interviewbit.com/problems/capacity-to-ship-packages-within-b-days/

int getDays(vector<int> &A, int cap) {
    int n = A.size();
    if (n==1 && A[0] > cap) return -1;

    int days = 0, currSum = A[0];
    for (int i=1; i<n; i++) {
        if (currSum > cap) return -1;
        
        if (currSum + A[i] > cap) {
            currSum = A[i];
            days++;
        } else currSum += A[i];
    }
    return days + 1;
}

int Solution::solve(vector<int> &A, int B) {
    int low = 1, high = 0, mid, midDays, ans = -1, n = A.size();
    for (auto &a: A) high += a;
    
    while (low <= high) {
        mid = (high + low) / 2;
        midDays = getDays(A, mid);
        
        if (midDays == -1 || midDays > B)
            low = mid + 1;
        else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}
