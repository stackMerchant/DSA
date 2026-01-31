// https://www.interviewbit.com/problems/permutations/

// Solution, order doesn't matter here, they sort before checking
// If want proper ordering, use deque or something

vector<vector<int>> getPerms(int i, vector<int> &A) {
    if (i == A.size() - 1) return {{A[i]}};
    
    vector<vector<int>> ret, perms;
    for (int j=i; j<A.size(); j++) {
        swap(A[i], A[j]); // swap with i with j
        perms = getPerms(i+1, A); // get permutataions
        for (auto p: perms) {
            p.push_back(A[i]);
            ret.push_back(p);
        }
        swap(A[i], A[j]); // swap with i with j
    }
    return ret;
}

vector<vector<int>> Solution::permute(vector<int> &A) {
    return getPerms(0, A);
}