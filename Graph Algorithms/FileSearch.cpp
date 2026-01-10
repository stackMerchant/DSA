// https://www.interviewbit.com/problems/file-search/

int findParent(vector<int> &parents, int item) {
    if (parents[item] == item) return item;
    parents[item] = findParent(parents, parents[item]);
    return parents[item];
}

int Solution::breakRecords(int A, vector<vector<int> > &B) {
    // Initialize parents and ranks
    vector<int> parents;
    vector<int> ranks(A+1, 1);
    for (int i=0; i<=A; i++) parents.push_back(i);    
    
    // Join all edges
    for (int i=0; i < B.size(); i++) {
        int p1 = findParent(parents, B[i][0]);
        int p2 = findParent(parents, B[i][1]);
        
        if (p1 != p2) {
            if (ranks[p1] >= ranks[p2]) {
                parents[p2] = p1;
                ranks[p1] += ranks[p2];
            } else {
                parents[p1] = p2;
                ranks[p2] += ranks[p1];
            }
        }
    }
    
    // Find unique parents
    unordered_set<int> uniqueParents;
    for (int i=1; i<=A; i++) uniqueParents.insert(findParent(parents, i));
    return uniqueParents.size();
}
