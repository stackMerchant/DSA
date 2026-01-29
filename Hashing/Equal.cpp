// https://www.interviewbit.com/problems/equal/

bool isValid(vector<int> &a) {
    // Conditions directly from question
    return a[0]<a[2] && a[1]!=a[2] && a[1]!=a[3];
}

bool shouldUpdate(vector<int> &a, vector<int> &b) {
    // Check if a is unset or lexicographically greater
    if (a.size() == 0) return true;
    if (a[0] != b[0]) return a[0] > b[0];
    if (a[1] != b[1]) return a[1] > b[1];
    if (a[2] != b[2]) return a[2] > b[2];
    if (a[3] != b[3]) return a[3] > b[3];
    return false;
}

vector<int> Solution::equal(vector<int> &A) {
    int n = A.size();
    // Map of sum to first pair of indices giving that sum
    // First pair will beat later pairs lexicographically
    unordered_map<int, pair<int, int>> map;
    
    vector<int> ret;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int currSum = A[i] + A[j];

            // If current pair sum is not present, add it and continue
            if (map.find(currSum) == map.end()) map[currSum] = {i, j};
            else {
                // A pair with current pair sum exists
                pair<int, int> existing = map[currSum];
                vector<int> currComb = {existing.first, existing.second, i, j}; 
                // Validate if current combination of indices is valid
                // And if yes, should we update preexisting answer by comparing lexicographically
                if (isValid(currComb) && shouldUpdate(ret, currComb)) ret = currComb;
            }
        }
    }
    return ret;
}
