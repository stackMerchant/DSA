// https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-i/

int Solution::maxProfit(const vector<int> &A) {
    int ret = 0, minYet = -1;
    for (int a: A) {
        if (minYet == -1) {
            minYet = a;
        }
        ret = max(ret, a - minYet);
        minYet = min(minYet, a);
    }
    return ret;
}
