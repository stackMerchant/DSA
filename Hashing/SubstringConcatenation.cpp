// https://www.interviewbit.com/problems/substring-concatenation/

void removeFromMap(string s, unordered_map<string, int> &map) {
    if (map.find(s) == map.end()) return;
    else if (map[s] == 1) map.erase(s);
    else map[s]--;
}

void addToMap(string s, unordered_map<string, int> &map) {
    if (map.find(s) == map.end()) map[s] = 1;
    else map[s]++;
}

bool check(int i, int l, string A, unordered_map<string, int> map) {
    if (map.empty()) return true;
    if (i >= A.size()) return false;
    
    string curr = A.substr(i, l);
    if (map.find(curr) == map.end()) return false;
    
    removeFromMap(curr, map);
    bool result = check(i + l, l, A, map);
    addToMap(curr, map);
    return result;
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    unordered_map<string, int> map;
    for (auto &b: B) addToMap(b, map);
    
    int n = A.size(), l = B[0].size();
    vector<int> ret;
    for (int i=0; i<n; i++) {
        if (check(i, l, A, map)) ret.push_back(i);
    }
    return ret;
}
