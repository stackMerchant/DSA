// https://www.interviewbit.com/problems/black-shapes/

void markVisited(vector<string> &A, int m, int n, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j>= n) return;
    if (A[i][j] == 'O') return;
    
    A[i][j] = 'O';
    markVisited(A, m, n, i+1, j);
    markVisited(A, m, n, i-1, j);
    markVisited(A, m, n, i, j+1);
    markVisited(A, m, n, i, j-1);
    return;
}

int Solution::black(vector<string> &A) {
    int m = A.size(), n = A[0].size(), ret = 0;
    
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (A[i][j] == 'X') {
                markVisited(A, m, n, i, j);
                ret++;
            }
            
    return ret;
}
