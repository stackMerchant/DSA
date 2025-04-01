// https://www.interviewbit.com/problems/word-search-board/

int func(vector<string> &A, string B, int m, int n, int i, int j, int s) {
    // If all characters are matched
    if(s >= B.size()) return 1;
    
    // If out of bounds or character is not matching
    if(i < 0 || i >= m || j < 0 || j >= n) return 0;
    if(A[i][j] != B[s]) return 0;
    
    // Visit adjacent
    if(func(A, B, m, n, i+1, j, s+1)) return 1;
    if(func(A, B, m, n, i-1, j, s+1)) return 1;
    if(func(A, B, m, n, i, j+1, s+1)) return 1;
    if(func(A, B, m, n, i, j-1, s+1)) return 1;
    
    // Not matched
    return 0;
}

int Solution::exist(vector<string> &A, string B) {
    int m = A.size(), n = A[0].size();

    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (func(A, B, m, n, i, j, 0)) return 1;

    return 0;
}