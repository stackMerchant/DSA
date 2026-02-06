// https://www.interviewbit.com/problems/word-break/

// Solution 1 => Normal dp vector

int Solution::wordBreak(string A, vector<string> &B) {
    // Create set
    unordered_set<string> set;
    for (auto b: B) set.insert(b);
    
    // dp[i] => if prefix with i elements of A can be created
    int n = A.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true; // With 0 elements of A, creation is possible

    for (int i=1; i<=n; i++) {
        if (dp[i-1]) { // If i-1 was possible, then only calculate from i
            string temp = "";
            for (int j=i; j <= n && j < i+20; j++) { // len(B[i]) <= 20
                temp = temp + A[j-1];
                if (set.find(temp) != set.end()) dp[j] = true;
            }
        }
    }
    return dp[n];
}

// Solution 2 => Below works even without B<20 check, test cases must be skewed OR I am missing something

int Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> dict;
    for (auto it : B) dict.insert(it);
    
    vector<bool> dp(A.size() + 1, 0);
    dp[A.size()] = 1;
    
    for (int i = A.size() - 1; i >= 0; i--) {
        string tmp = "";
        for (int j = i; j < A.size(); j++) {
            if (dp[i]) break;
            tmp += A[j];
            if (dict.find(tmp) != dict.end()) dp[i] = dp[j + 1];
        }
    }

    if (dp[0]) return 1;
    return 0;
}