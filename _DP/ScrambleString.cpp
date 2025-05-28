// https://www.interviewbit.com/problems/scramble-string/

// Solution 1 => Recursion with memo

int checkScramble(string A, string B, int a, int b, int len, vector<vector<vector<int>>> &dp) {
    // If already calculated
    if (dp[a][b][len] != -1) return dp[a][b][len];
    
    // If lenght is 1, just check if characters are same
    if (len == 1) {
        dp[a][b][len] = A[a] == B[b] ? 1 : 0;
        return dp[a][b][len];
    }   

    // Partition 1:
    // A of length l and len-l
    // B of length l and len-l
    // Compare respectively
    
    // Partition 2:
    // A of length l and len-l
    // B of length len-l and l
    // Compare cross
    
    for (int l=1; l < len; l++) {
        if (
            (checkScramble(A, B, a, b, l, dp) && checkScramble(A, B, a+l, b+l, len-l, dp)) ||
            (checkScramble(A, B, a, b+(len-l), l, dp) && checkScramble(A, B, a+l, b, len-l, dp))
        ) {
            dp[a][b][len] = 1;
            return dp[a][b][len];
        }
    }

    dp[a][b][len] = 0;
    return dp[a][b][len];
}

int Solution::isScramble(const string A, const string B) {
    int n = A.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n+1, -1)));
    return checkScramble(A, B, 0, 0, n, dp) == 1;
}

// Solution 2 => witout memo

int check(string &A, string &B) {
    // Check if strings have same characters
    string At = A; sort(At.begin(), At.end());
    string Bt = B; sort(Bt.begin(), Bt.end());
    if (At.compare(Bt) != 0) return 0;
    
    int n = A.size();
    if(n == 1 || n == 2) return 1;

    for (int i=0; i < n; i++) {
        string a1 = A.substr(0,i), a2 = A.substr(i);
        string b1 = B.substr(0,i), b2 = B.substr(i);
        if(check(a1, b1) && check(a2, b2)) return 1;
    }
    reverse(B.begin(), B.end());
    for (int i=0; i < n; i++) {
        string a1 = A.substr(0,i), a2 = A.substr(i);
        string b1 = B.substr(0,i), b2 = B.substr(i);
        if(check(a1, b1) && check(a2, b2)) return 1;
    }
    return 0;
}

int Solution::isScramble(const string A, const string B) {
    string At = A, Bt = B;
    return check(At, Bt);
}