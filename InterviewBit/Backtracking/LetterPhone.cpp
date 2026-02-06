// https://www.interviewbit.com/problems/letter-phone/

unordered_map<char, string> prepareMap() {
    unordered_map<char, string> map;
    map['0'] = "0";
    map['1'] = "1";
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";
    return map;
}

void trav(int i, string currString, vector<string> &ans, string &A, unordered_map<char, string> &map) {
    if (i == A.size()) {
        ans.push_back(currString);
        return;
    }
    
    for (auto &c: map[A[i]]) trav(i+1, currString + c, ans, A, map);
}

vector<string> Solution::letterCombinations(string A) {
    unordered_map<char, string> map = prepareMap();
    vector<string> ans;
    trav(0, "", ans, A, map);
    return ans;
}
