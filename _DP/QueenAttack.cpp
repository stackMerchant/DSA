// https://www.interviewbit.com/problems/queen-attack/

bool isValid(int m, int n, int a, int b) {
    if (a < 0 || a >= m || b < 0 || b >= n) return false;
    return true;
}

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int m = A.size(), n = A[0].size(), a, b;
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (A[i][j] == '1') {
                a = i+1; b = j;
                while (a<m && A[a][b]!='1') {dp[a][b]+=1; a++;}
                if (isValid(m, n, a, b)) dp[a][b] += 1;
                
                a = i-1; b = j;
                while (a>=0 && A[a][b]!='1') {dp[a][b]+=1; a--;}
                if (isValid(m, n, a, b)) dp[a][b] += 1;
                
                a = i; b = j+1;
                while (b<n && A[a][b]!='1') {dp[a][b]+=1; b++;}
                if (isValid(m, n, a, b)) dp[a][b] += 1;
                
                a = i; b = j-1;
                while (b>=0 && A[a][b]!='1') {dp[a][b]+=1; b--;}
                if (isValid(m, n, a, b)) dp[a][b] += 1;
                
                a = i-1; b = j-1;
                while (a>=0 && b>=0 && A[a][b]!='1') {dp[a][b]+=1; a--; b--;}
                if (isValid(m, n, a, b)) dp[a][b] += 1;
                
                a = i+1; b = j+1;
                while (a<m && b<n && A[a][b]!='1') {dp[a][b]+=1; a++; b++;}
                if (isValid(m, n, a, b)) dp[a][b] += 1;
                
                a = i-1; b = j+1;
                while (a>=0 && b<n && A[a][b]!='1') {dp[a][b]+=1; a--; b++;}
                if (isValid(m, n, a, b)) dp[a][b] += 1;
                
                a = i+1; b = j-1;
                while (a<m && b>=0 && A[a][b]!='1') {dp[a][b]+=1; a++; b--;}
                if (isValid(m, n, a, b)) dp[a][b] += 1;
            }
        }
    }
    return dp;
}
