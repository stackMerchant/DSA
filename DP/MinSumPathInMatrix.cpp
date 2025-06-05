// https://www.interviewbit.com/problems/min-sum-path-in-matrix/

int Solution::minPathSum(vector<vector<int> > &A) {
    int a = A.size(), b = A[0].size();
    
    for (int i=1; i<a; i++) A[i][0] += A[i-1][0];
    for (int j=1; j<b; j++) A[0][j] += A[0][j-1];
    
    for (int i=1; i<a; i++)
        for (int j=1; j<b; j++)
            A[i][j] += min(A[i-1][j], A[i][j-1]);

    return A[a-1][b-1];
}