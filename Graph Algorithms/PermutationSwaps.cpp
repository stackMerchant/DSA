// https://www.interviewbit.com/problems/permutation-swaps/

// All nodes in a graph created by joining swap positions are swappable
// So just find disjoint sets and for any swap check if the are connected

int findParent(int node, vector<int> &parents) {
    if (parents[node] == node) return node;
    parents[node] = findParent(parents[node], parents);
    return parents[node];
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    // create disjoint sets
    int n = A.size();
    vector<int> parents(n), rank(n, 1);
    for (int i=0; i<n; i++) parents[i] = i;
    
    for (auto &c: C) {
        int pc0 = findParent(c[0]-1, parents);
        int pc1 = findParent(c[1]-1, parents);
        if (pc0 != pc1) {
            if (rank[pc0] >= rank[pc1]) {
                parents[pc1] = pc0;
                rank[pc0] += rank[pc1];
            } else {
                parents[pc0] = pc1;
                rank[pc1] += rank[pc0];
            }
        }
    }
    
    // store position of each element in A
    unordered_map<int, int> mp;
    for (int i=0; i<n; i++) mp[A[i]] = i;
    
    for (int i=0; i<n; i++) {
        if (A[i] != B[i]) {
            int pCurrentNode = findParent(i, parents);
            int pDestNode = findParent(mp[B[i]], parents); // position where B[i] is
            if (pCurrentNode != pDestNode) return 0;
        }
    }
    
    return 1;
}
