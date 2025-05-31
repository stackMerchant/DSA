// https://www.interviewbit.com/problems/evaluate-expression-to-true/

#define mod 1003;
int getTrue(string s, int a, int b, vector<vector<int>> &dpt, vector<vector<int>> &dpf);

int getFalse(string s, int a, int b, vector<vector<int>> &dpt, vector<vector<int>> &dpf) {
    if (dpf[a][b] !=- 1) return dpf[a][b];
    if (a == b) return s[a]=='F' ? 1 : 0;
    
    int ret = 0;
    for (int i=a+1; i<b; i++) {
        int leftTrue = getTrue(s, a, i-1, dpt, dpf);
        int leftFalse = getFalse(s, a, i-1, dpt, dpf);
        int rightTrue = getTrue(s, i+1, b, dpt, dpf);
        int rightFalse = getFalse(s, i+1, b, dpt, dpf);
        
        if (s[i] == '&') ret += leftFalse * rightFalse + leftTrue * rightFalse + leftFalse * rightTrue;
        else if (s[i] == '^') ret += leftFalse * rightFalse + leftTrue * rightTrue;
        else if (s[i] == '|') ret += leftFalse * rightFalse;
    }
    dpf[a][b] = ret % mod;
    return dpf[a][b];
}

int getTrue(string s, int a, int b, vector<vector<int>> &dpt, vector<vector<int>> &dpf) {
    if (dpt[a][b] != -1) return dpt[a][b];
    if (a == b) return s[a]=='T' ? 1 : 0;
    
    int ret = 0;
    for (int i=a+1; i<b; i++) {
        int leftTrue = getTrue(s, a, i-1, dpt, dpf);
        int leftFalse = getFalse(s, a, i-1, dpt, dpf);
        int rightTrue = getTrue(s, i+1, b, dpt, dpf);
        int rightFalse = getFalse(s, i+1, b, dpt, dpf);
        
        if (s[i] == '&') ret += leftTrue * rightTrue;
        else if (s[i] == '^') ret += leftTrue * rightFalse + leftFalse * rightTrue;
        else if (s[i] == '|') ret += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
    }
    dpt[a][b] = ret % mod;
    return dpt[a][b];
}

int Solution::cnttrue(string A) {
    int n = A.size();
    vector<vector<int>> dpt(n, vector<int>(n, -1));
    vector<vector<int>> dpf(n, vector<int>(n, -1));
    return getTrue(A, 0, n-1, dpt, dpf);
}