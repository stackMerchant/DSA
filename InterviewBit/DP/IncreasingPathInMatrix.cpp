// https://www.interviewbit.com/problems/increasing-path-in-matrix/

int Solution::solve(vector<vector<int>> &A) {
    int n = A.size(), m = A[0].size();
    vector<vector<int>> path(n, vector<int>(m, -1));
    
    path[0][0] = 1;
    for (int i=1; i<n; i++) {
        if (A[i][0] > A[i-1][0] && path[i-1][0] != -1) {
            path[i][0] = path[i-1][0] + 1;
        }
    }
    
    for (int j=1; j<m; j++) {
        if (A[0][j] > A[0][j-1] && path[0][j-1] != -1) {
            path[0][j] = path[0][j-1] + 1;
        }
    }
    
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            if (A[i][j] > A[i-1][j] && path[i-1][j] != -1) {
                path[i][j] = path[i-1][j] + 1;
            }
            
            if (A[i][j] > A[i][j-1] && path[i][j-1] != -1) {
                path[i][j] = max(path[i][j], path[i][j-1] + 1);
            }
        }
    }
    return path[n-1][m-1];
}
