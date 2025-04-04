// https://www.interviewbit.com/problems/longest-arithmetic-progression/

// FIX THIS

// Giving TLE
// int Solution::solve(const vector<int> &A) {
//     int n = A.size();
// 	if (n < 3) return n;
    
//     int ret = 1, diff, maxj;
//     vector<unordered_map<int, int>> dp(n);
//     for (int i=1; i<n; i++) {
//         for (int j=0; j<i; j++) {
//             diff = A[i] - A[j];
            
//             dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1: 2;
//             ret = max(ret, dp[i][diff]);
//         }
//     }
//     return ret;
// }

// Working
int Solution::solve(const vector<int> &A) {
	int n = A.size();
	if (n < 3) return n;
    
    vector<vector<int>> dp(n, vector<int>(n, 2));
	map<int, int> pos;
    int ret = 2, prev;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			prev = 2 * A[i] - A[j];
			if (pos.count(prev) > 0) {
                dp[i][j] = max(dp[i][j], dp[pos[prev]][i] + 1);
                ret = max(ret, dp[i][j]);
            }
		}
		pos[A[i]] = i;
	}
	return ret;
}