// https://www.interviewbit.com/problems/anagrams/

vector<vector<int>> Solution::anagrams(const vector<string> &A) {
    unordered_map<string, vector<int>> map;
    
    for (int i=0; i<A.size(); i++) {
        string curr = A[i];
        sort(curr.begin(), curr.end());
        map[curr].push_back(i+1);
    }
    
    vector<vector<int>> ret;
    for (auto m: map) ret.push_back(m.second);
    return ret;
}
