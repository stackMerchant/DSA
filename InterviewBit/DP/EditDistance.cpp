// https://www.interviewbit.com/problems/edit-distance/

int Solution::minDistance(string A, string B) {
    int a = A.size(), b = B.size();

    vector<vector<int>> mat(a+1, vector<int>(b+1, -1));
    for (int i=0; i<=a; i++) mat[i][0] = i;
    for (int i=0; i<=b; i++) mat[0][i] = i;
    
    for (int i=1; i<=a; i++) {
        for (int j=1; j<=b; j++) {
            if (A[i-1] == B[j-1])
                mat[i][j] = mat[i-1][j-1];
            else
                mat[i][j] = min(min(mat[i-1][j], mat[i][j-1]), mat[i-1][j-1]) + 1;
        }
    }
    return mat[a][b];
}