// https://www.interviewbit.com/problems/combinations/

void trav(int i, int used, vector<int> &currList, vector<vector<int>> &ans, int &A, int &B) {
    if (used == B) {
        ans.push_back(currList);
        return;
    }
    if (i > A) return;
    
    currList.push_back(i);
    trav(i+1, used+1, currList, ans, A, B);
    currList.pop_back();
    trav(i+1, used, currList, ans, A, B);
}

vector<vector<int>> Solution::combine(int A, int B) {
    vector<vector<int>> ans;
    vector<int> currList;
    trav(1, 0, currList, ans, A, B);
    return ans;
}
