// https://www.interviewbit.com/problems/all-possible-combinations/

// Solution 1

void trav(int idx, string &currString, vector<string> &A, vector<string> &ret) {
    if (idx >= A.size()) {
        ret.push_back(currString);
        return;
    }
    
    for (auto &ch: A[idx]) {
        currString.push_back(ch);
        trav(idx+1, currString, A, ret);
        currString.pop_back();
    }
}

vector<string> Solution::specialStrings(vector<string> &A) {
    vector<string> ret;
    string currString = "";
    trav(0, currString, A, ret);
    return ret;
}

// Solution 2, not recommended
// Generate and return all combinations upstrem, use it recursively

vector<string> getPerm(vector<string> &A, int index) {
    int N = A.size();
    if (index >= N) return { "" };
    
    vector<string> belowPerm = getPerm(A, index + 1), ret;
    
    for (char c: A[index]) {
        for (int j=0; j<belowPerm.size(); j++) {
            ret.push_back(c + belowPerm[j]);
        }
    }
    return ret;
}

vector<string> Solution::specialStrings(vector<string> &A) {
    int N = A.size();
    for (int i=0; i<N; i++) sort(A[i].begin(), A[i].end());
    return getPerm(A, 0);
}
