# [LC 943]

## Solution 1
- Basic solution
- Gives TLE

```cpp
class Solution {
public:

    bool isUsed(int j, int mask) {
        return mask & (1<<j);
    }

    int use(int j, int mask) {
        return mask | (1<<j);
    }

    string merge(string s1, string s2) { // s1 + s2
        int len = min(s1.length(), s2.length());
        for (int l=len; l>0; l--) {
            string s1Suffix = s1.substr(s1.length() - l);
            string s2Prefix = s2.substr(0, l);
            if (s1Suffix == s2Prefix) {
                return s1 + s2.substr(l);
            }
        }
        return s1 + s2;
    }

    string getShorterString(string s1, string s2) {
        if (s1 == "-1") return s2;
        if (s2 == "-1") return s1;
        if (s1.length() < s2.length()) return s1;
        return s2;
    }

    string findShortestString(int i, int mask, int &targetMask, vector<string> &words, vector<vector<string>> &dp) {
        if (mask == targetMask) dp[i][mask] = words[i];
        if (dp[i][mask] != "-1") return dp[i][mask];

        int n = words.size();
        string shortestString = "-1", currShortestString;

        for (int j=0; j<n; j++) if (!isUsed(j, mask)) {
            currShortestString = merge(words[i], findShortestString(j, use(j, mask), targetMask, words, dp));
            shortestString = getShorterString(shortestString, currShortestString);
        }
        dp[i][mask] = shortestString;
        return dp[i][mask];
    }

    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        int targetMask = (1<<n) - 1;

        vector<vector<string>> dp(n, vector<string>(1<<n, "-1"));

        string shortestString = "-1", currShortestString;
        for (int i=0; i<n; i++) {
            currShortestString = findShortestString(i, use(i, 0), targetMask, words, dp);
            shortestString = getShorterString(shortestString, currShortestString);
        }

        return shortestString;
    }
};
```

## Solution 2

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();

        // Step 1: overlap[i][j]
        vector<vector<int>> overlap(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int m = min(A[i].size(), A[j].size());
                for (int k = m; k >= 0; k--) {
                    if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }

        // Step 2: dp + parent
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));

        // init
        for (int i = 0; i < n; i++) {
            dp[1 << i][i] = 0;
        }

        // Step 3: fill dp, TSP CORE
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int last = 0; last < n; last++) {
                if (dp[mask][last] == -1) continue;

                for (int nxt = 0; nxt < n; nxt++) {
                    if (mask & (1 << nxt)) continue;

                    int newMask = mask | (1 << nxt);
                    int val = dp[mask][last] + overlap[last][nxt];

                    if (val > dp[newMask][nxt]) {
                        dp[newMask][nxt] = val;
                        parent[newMask][nxt] = last;
                    }
                }
            }
        }

        // Step 4: find best end
        int full = (1 << n) - 1;
        int last = 0;
        for (int i = 1; i < n; i++) {
            if (dp[full][i] > dp[full][last]) {
                last = i;
            }
        }

        // Step 5: reconstruct order
        vector<int> path;
        int mask = full;

        while (last != -1) {
            path.push_back(last);
            int p = parent[mask][last];
            mask ^= (1 << last);
            last = p;
        }

        reverse(path.begin(), path.end());

        // Step 6: build answer
        string res = A[path[0]];
        for (int i = 1; i < path.size(); i++) {
            int u = path[i - 1];
            int v = path[i];
            res += A[v].substr(overlap[u][v]);
        }

        return res;
    }
};
```