// https://www.interviewbit.com/problems/kingdom-war/

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size();
    
    int ans = A[n-1][m-1]; // initialize with max value
    for (int j=m-2; j>=0; j--) { // fill bottom row
        A[n-1][j] += A[n-1][j+1];
        ans = max(ans, A[n-1][j]);
    }
    for (int i=n-2; i>=0; i--) { // fill right column
        A[i][m-1] += A[i+1][m-1];
        ans = max(ans, A[i][m-1]);
    }

    for (int i=n-2; i>=0; i--) {
        for (int j=m-2; j>=0; j--) {
            A[i][j] += A[i+1][j] + A[i][j+1] - A[i+1][j+1];
            ans = max(ans, A[i][j]);
        }
    }
    return ans;
}
