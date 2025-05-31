// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if (n < 2) return 0;
    
    vector<int> inc(n, 0), dec(n, 0);
    int minTill = A[0], maxProfit = 0;
    for (int i=1; i<n; i++) {
        maxProfit = max(maxProfit, A[i] - minTill);
        inc[i] = maxProfit;
        minTill = min(minTill, A[i]);
    }
    
    int maxTill = A[n-1]; maxProfit = 0;
    for (int i=n-2; i>=0; i--) {
        maxProfit = max(maxProfit, maxTill - A[i]);
        dec[i] = maxProfit;
        maxTill = max(maxTill, A[i]);
    }
    
    maxProfit = 0;
    for (int i=0; i<n; i++)
        maxProfit = max(maxProfit, inc[i] + dec[i]);
    return maxProfit;
}