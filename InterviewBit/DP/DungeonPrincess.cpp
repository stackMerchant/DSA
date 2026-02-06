// https://www.interviewbit.com/problems/dungeon-princess/

int Solution::calculateMinimumHP(vector<vector<int>> &A) {
    int n = A.size(), m = A[0].size();
    
    // Fill edges
    A[n-1][m-1] = max(0, 0 - A[n-1][m-1]);
    for (int i=n-2; i>=0; i--) A[i][m-1] = max(0, A[i+1][m-1] - A[i][m-1]);
    for (int j=m-2; j>=0; j--) A[n-1][j] = max(0, A[n-1][j+1] - A[n-1][j]);
    
    // Fill rest of the matrix
    for (int i=n-2; i>=0; i--) {
        for (int j=m-2; j>=0; j--) {
            A[i][j] = max(0, min(A[i+1][j], A[i][j+1]) - A[i][j]);
        }
    }
    
    return A[0][0] + 1;
}
