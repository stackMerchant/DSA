// https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/

int Solution::solve(vector<vector<int> > &A) {
    if (A.size() <= 0) return 0;    
    int n = A.size(), m = A[0].size(), ret = 0;

    for (int i=1; i<n; i++)
        for (int j=0; j<m; j++)
            if (A[i][j] == 1) A[i][j] = A[i-1][j] + 1;
    
    for (int i=0; i<n; i++)
        sort(A[i].rbegin(), A[i].rend());

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            ret = max(ret, A[i][j] * (j+1));
    
    return ret;
}
