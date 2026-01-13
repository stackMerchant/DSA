// https://www.interviewbit.com/problems/region-in-binarymatrix/

vector<pair<int, int>> getNextPoints(int i, int j, int n, int m) {
    vector<pair<int, int>> ret;
    vector<int> di = {1,1,1,-1,-1,-1,0,0};
    vector<int> dj = {1,-1,0,1,-1,0,1,-1};
    
    for (int t=0; t<8; t++) {
        int ti = i + di[t];
        int tj = j + dj[t];
        if (ti >=0 && tj >=0 && ti < n & tj < m) {
            ret.push_back({ti, tj});
        }
    }
    return ret;
}

int trav(int i, int j, int n, int m, vector<vector<int> > &A) {
    if (A[i][j] == 0) return 0; // empty cell
    if (A[i][j] == 2) return 0; // visited cell
    A[i][j] = 2; // visit the cell
    int ret = 1; // count this cell
    
    for (auto [ti, tj]: getNextPoints(i, j, n, m)) {
        ret += trav(ti, tj, n, m, A);
    }
    return ret;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size(), m = A[0].size(), ret = 0;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (A[i][j] == 1) {
                ret = max(ret, trav(i, j, n, m, A));
            }
        }
    }
    return ret;
}
