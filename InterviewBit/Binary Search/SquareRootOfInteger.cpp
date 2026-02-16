// https://www.interviewbit.com/problems/square-root-of-integer/

int Solution::sqrt(int A) {
    long long int low = 0, high = A, ans, mid, sq;
    
    while (low <= high) {
        mid = (high + low) / 2;
        sq = mid * mid;
        
        if (sq <= A) {
            ans = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    
    return ans;
}
