// https://www.interviewbit.com/problems/painters-partition-problem/

#define ll long long int

bool check(vector<int> &C, int painters, int limit) {
    int currSum = 0, usedPainters = 1;
    for (auto &c: C) {
        if (c > limit) return false;
        
        if (currSum + c <= limit) currSum += c;
        else {
            usedPainters++;
            currSum = c;
        }
    }
    return usedPainters <= painters;
}

int Solution::paint(int A, int B, vector<int> &C) {
    ll painters = A, time = B, mod = 1e7 + 3, low, high, mid, ans;
    
    low = 0; high = 0;
    for (auto &c: C) {
        low = max(low, (ll)c);
        high += c;
    }
    
    while (low <= high) {
        mid = (high + low) / 2;
        if (check(C, painters, mid)) {
            high = mid - 1;
            ans = mid;
        } else low = mid + 1;
    }
    return (ans * time) % mod;
}
