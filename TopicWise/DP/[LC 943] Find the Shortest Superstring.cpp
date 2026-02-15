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