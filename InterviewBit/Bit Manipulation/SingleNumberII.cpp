// https://www.interviewbit.com/problems/single-number-ii/

int Solution::singleNumber(const vector<int> &A) {
    int ans = 0;
    for (int b=31; b>=0; b--) {
        int mask = 1<<b;
        int count = 0;
        for (int i=0; i<A.size(); i++)
            if (A[i] & mask) count++;
        
        int isSet = count % 3;
        ans *= 2;
        ans += isSet;
    }
    return ans;
}
