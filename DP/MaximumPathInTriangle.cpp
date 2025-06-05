// https://www.interviewbit.com/problems/maximum-path-in-triangle/

int Solution::solve(vector<vector<int> > &A) {
    int N = A.size();
    int topLeft, top, maxCell, maxPath = 0;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<=i; j++) {
            topLeft = (i > 0 && j > 0) ? A[i-1][j-1] : 0;
            top = (i > 0 && j < i) ? A[i-1][j] : 0;
            
            if (topLeft != -1 && top != -1) maxCell = max(topLeft, top);
            else if (topLeft != -1) maxCell = topLeft;
            else if (top != -1) maxCell = top;
            else maxCell = 0;
            
            A[i][j] += maxCell;
            if (i == N-1) maxPath = max(maxPath, A[i][j]);
        }
    }
    
    return maxPath;
}