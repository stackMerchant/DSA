// https://www.interviewbit.com/problems/two-out-of-three/

vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    int na, nb, nc; na = A.size(); nb = B.size(); nc = C.size();
    unordered_set<int> sa, sb, sc;
    for(int i=0; i<na; i++) sa.insert(A[i]);
    for(int i=0; i<nb; i++) sb.insert(B[i]);
    for(int i=0; i<nc; i++) sc.insert(C[i]);
    
    unordered_set<int> ret;
    
    for(int i=0; i<na; i++) {
        if(sb.find(A[i]) != sb.end() || sc.find(A[i]) != sc.end()) ret.insert(A[i]);
    }
    
    for(int i=0; i<nb; i++) {
        if(sa.find(B[i]) != sa.end() || sc.find(B[i]) != sc.end()) ret.insert(B[i]);
    }
    
    for(int i=0; i<nc; i++) {
        if(sb.find(C[i]) != sb.end() || sa.find(C[i]) != sa.end()) ret.insert(C[i]);
    }
    
    vector<int> retV;
    for(auto it = ret.begin(); it != ret.end(); it++) {
        retV.push_back(*it);
    }
    sort(retV.begin(), retV.end());
    return retV;
}
