// https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/

vector<int> subtract(vector<int> &currRow, vector<int> &prevRow) {
    vector<int> subRow;
    for (int i=0; i<currRow.size(); i++)
        subRow.push_back(currRow[i] - prevRow[i]);
    return subRow;
}

// Prefix sum + hashing
int process(vector<int> row) {
    for (int i=1; i<row.size(); i++) row[i] += row[i-1];
    
    int ret = 0;
    unordered_map<int, int> map; map[0] = 1;
    for (int i=0; i<row.size(); i++) {
        ret += map[row[i]];
        map[row[i]]++;
    }
    return ret;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    
    // At row i, sum of all rows above i
    for (int i=1; i<n; i++)
        for (int j=0; j<A[i].size(); j++)
            A[i][j] += A[i-1][j];

    // Select row i and iterate 0 to i, subtract and find 0 subarray count
    int ret = 0;
    vector<int> currRow, prevRow, subRow;
    for (int i=0; i<n; i++) {
        currRow = A[i];
        for (int ii=-1; ii<i; ii++) {
            prevRow = ii>=0 ? A[ii] : vector<int>(currRow.size(), 0);
            subRow = subtract(currRow, prevRow);
            ret += process(subRow);
        }
    }
    return ret;
}
