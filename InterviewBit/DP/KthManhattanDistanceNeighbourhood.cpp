// https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/

vector<vector<int>> Solution::solve(int K, vector<vector<int>> &M) {
    int a = M.size(), b = M[0].size();
    
    vector<vector<int>> _M = M;
    for (int k=0; k<K; k++) {
        for (int i=0; i<a; i++) {
            for (int j=0; j<b; j++) {
                int above = i-1 >= 0 ? M[i-1][j] : 0;
                int below = i+1 < a ? M[i+1][j] : 0;
                int left = j-1 >= 0 ? M[i][j-1]: 0;
                int right = j+1 < b ? M[i][j+1]: 0;
                _M[i][j] = max(_M[i][j], max(max(above, below), max(left, right)));
            }
        }
        M = _M;
    }
    return M;
}