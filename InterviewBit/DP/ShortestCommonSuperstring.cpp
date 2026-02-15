// https://www.interviewbit.com/problems/shortest-common-superstring/

void removeOverlaps(vector<string>& A) {
    int n = A.size();
    
	// Check for completely overlapping strings
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (i!=j && A[i].find(A[j]) != string::npos)
                A[j] = "";
    
    // New vector without empty string
 	vector<string> newA;
 	for (int i=0; i<n; i++)
        if (A[i] != "")
            newA.push_back(A[i]);

    A = newA;
}

vector<vector<int>> prepareOverlap(vector<string>& A) {
    int n = A.size();
    vector<vector<int>> overlap(n, vector<int>(n, 0));
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i != j) {
                int len = min(A[i].size(), A[j].size()); // max overlap length
                for (int l=len; l>0; l--) {
                    string iSuffix = A[i].substr(A[i].size() - l);
                    string jPrefix = A[j].substr(0, l);
                    if (iSuffix == jPrefix) {
                        overlap[i][j] = l;
                        break;
                    }
                }
            }
        }
    }
    
    return overlap;
}

int getSum(vector<string>& A) {
    int sum = 0;
    for (auto a: A) sum += a.size();
    return sum;
}

int findMaxOverlap(int i, int mask, int targetMask, vector<string> &A, vector<vector<int>> &overlap, vector<vector<int>> &dp) {
    if (dp[i][mask] != -1) return dp[i][mask];
    if (mask == targetMask) return 0;

    int n = A.size();
    int maxOverlap = 0;
    for (int j=0; j<n; j++) {
        if (!(mask & 1<<j)) { // if not used
            int currOverlap = overlap[i][j] + findMaxOverlap(j, (mask | 1<<j), targetMask, A, overlap, dp);
            maxOverlap = max(maxOverlap, currOverlap);
        }
    }
    
    dp[i][mask] = maxOverlap;
    return dp[i][mask];
}

int Solution::solve(vector<string>& A) {
	removeOverlaps(A); // remove strings that completely overlap
    vector<vector<int>> overlap = prepareOverlap(A); // overlap length when i + j, j is added at the back of i

    int n = A.size();
    int totalLength = getSum(A);
    int minLength = INT_MAX;
    int targetMask = (1<<n) - 1;
    vector<vector<int>> dp(n, vector<int>(1<<n, -1));
    for (int i=0; i<n; i++) {
        int currLength = totalLength - findMaxOverlap(i, 1<<i, targetMask, A, overlap, dp);
        minLength = min(minLength, currLength);
    }
    
    return minLength;
}
