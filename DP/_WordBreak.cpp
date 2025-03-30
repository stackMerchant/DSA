// https://www.interviewbit.com/problems/word-break/

// int Solution::wordBreak(string A, vector<string> &B) {
//     unordered_set<string> set;
//     for (string b: B) set.insert(b);
    
//     int N = A.size();
//     vector<bool> dp(N + 1, false);
//     dp[N] = true;
    
//     for (int i = N; i>0; i--) {
//         if (dp[i]) {
//             string s = "";
//             for (int j=i-1;j>=0;j--) {
//                 s = A[j] + s;
//                 if (set.find(s) != set.end()) dp[j] = true;
//             }
//         }
//     }
//     return dp[0] ? 1 : 0;
// }

// Above correct but TLE
// Fast (below or above), depends on the test cases
// In this case cause B < 20, below is faster

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
            if (dict.find(tmp) != dict.end()) {
                dp[i] = dp[j + 1];
            }
        }
    }
    if (dp[0])
        return 1;
    return 0;
}

// -1 not calculated
// 0 false
// 1 true

// int check(vector<short> &dp, string A, int i, unordered_set<string> dict) {
//     int N = A.size();
//     if (i >= N) return 1;
    
//     int rest;
//     if (dp[i] == -1) {
//         dp[i] = 0;
//         string s = "";
//         for (int j=i; j<N; j++) {
//             s += A[j];
//             if (dict.find(s) != dict.end()) {
//                 rest = check(dp, A, j + 1, dict);
//                 if (rest == 1) {
//                     dp[i] = 1;
//                     break;
//                 }
//             }
//         }
//     }
    
//     return dp[i];
// }

// int Solution::wordBreak(string A, vector<string> &B) {
//     unordered_set<string> dict;
//     for (string b: B) dict.insert(b);
    
//     vector<short> dp(A.size(), -1);
    
//     return check(dp, A, 0, dict);
// }