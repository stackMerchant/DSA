// https://www.interviewbit.com/problems/longest-consecutive-sequence/

int findSeq(int a, unordered_set<int> &set, unordered_map<int, int> &dp) {
    if (dp.find(a) != dp.end()) return dp[a];
    if (set.find(a) == set.end()) return 0;
    dp[a] = 1 + findSeq(a+1, set, dp);
    return dp[a];
}

int Solution::longestConsecutive(const vector<int> &A) {
    unordered_set<int> set;
    unordered_map<int, int> dp;
    
    for (auto a: A) set.insert(a);
    
    int maxSeq = 1;
    for (auto a: A) {
        maxSeq = max(maxSeq, findSeq(a, set, dp));
    }
    return maxSeq;
}