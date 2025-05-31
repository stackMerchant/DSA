// https://www.interviewbit.com/problems/unique-paths-in-a-grid/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int a = A.size(), b = A[0].size();
    vector<vector<int>> mat(a, vector<int>(b, 0));
    
    if (A[0][0] != 1) mat[0][0] = 1;
    for (int i=1; i<a; i++) if (A[i][0] != 1) mat[i][0] = mat[i-1][0];
    for (int j=1; j<b; j++) if (A[0][j] != 1) mat[0][j] = mat[0][j-1];
    
    for (int i=1; i<a; i++)
        for (int j=1; j<b; j++)
            if (A[i][j] != 1)
                mat[i][j] = mat[i-1][j] + mat[i][j-1];

    return mat[a-1][b-1];
}