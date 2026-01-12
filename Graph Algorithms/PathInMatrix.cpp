// https://www.interviewbit.com/problems/path-in-matrix/

vector<pair<int, int>> getValidNextPoints(int n, int i, int j) {
    vector<pair<int, int>> ret;
    if (i+1 < n) ret.push_back({i+1, j});
    if (i-1 >= 0) ret.push_back({i-1, j});
    if (j+1 < n) ret.push_back({i, j+1});
    if (j-1 >= 0) ret.push_back({i, j-1});
    return ret;
}

int Solution::checkPath(vector<vector<int> > &A) {
    // Extract source, destination and prepare visited matrix
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int n = A.size(), si, sj, di, dj; // source/destination i/j
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (A[i][j] == 1) {
                si = i;
                sj = j;
            } else if (A[i][j] == 2) {
                di = i;
                dj = j;
            } else if (A[i][j] == 0) {
                visited[i][j] = true;
            }
        }
    }
    
    // BFS
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    
    while (!q.empty()) {
        auto [ci, cj] = q.front(); q.pop(); // current i/j
        vector<pair<int, int>> validNextPoints = getValidNextPoints(n, ci, cj);
    
        for (auto [ni, nj]: validNextPoints) { // next i/j
            if (ni == di && nj == dj) return 1;
            if (!visited[ni][nj]) {
                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
    
    return 0;
}
