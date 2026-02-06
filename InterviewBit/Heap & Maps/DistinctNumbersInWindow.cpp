// https://www.interviewbit.com/problems/distinct-numbers-in-window/

void insert(unordered_map<int, int> &um, int x) {
    if (um.find(x) == um.end()) um[x] = 0;
    um[x]++;
}

void remove(unordered_map<int, int> &um, int x) {
    if (um.find(x) == um.end()) return;
    um[x]--;
    if (um[x] == 0) um.erase(x);
}

vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> ret;
    unordered_map<int, int> um;
    for (int i=0; i<B; i++) insert(um, A[i]);
    ret.push_back(um.size());
    
    for (int i=B; i < A.size(); i++) {
        remove(um, A[i-B]);
        insert(um, A[i]);
        ret.push_back(um.size());
    }
    return ret;
}
