// https://www.interviewbit.com/problems/subsets-ii/

void trav(int i, vector<int> &currList, vector<int> &list, unordered_map<int, int> &map, vector<vector<int>> &ans) {
    if (i >= list.size()) return;
    
    /* With this element */
    
    int element = list[i];
    int count = map[element];
    
    // Add elements and into ans
    for (int j=0; j<count; j++) {
        currList.push_back(list[i]);
        ans.push_back(currList);
    }
    
    // Remove one by one and trav
    for (int j=0; j<count; j++) {
        trav(i+1, currList, list, map, ans);
        currList.pop_back();
    }
    
    /* Without this element */
    trav(i+1, currList, list, map, ans);
}

vector<vector<int>> Solution::subsetsWithDup(vector<int> &A) {
    unordered_map<int, int> map;
    for (auto &a: A) map[a]++;
    
    vector<int> list;
    for (auto &m: map) list.push_back(m.first);
    sort(list.begin(), list.end());
    
    vector<vector<int>> ans;
    ans.push_back({});
    
    vector<int> currList;
    trav(0, currList, list, map, ans);
    return ans;
}
