// https://www.interviewbit.com/problems/gray-code/

// Solution 1, with recursion

void process(int bit, vector<int> &ans) {
    vector<int> rev = ans;
    reverse(rev.begin(), rev.end());
    
    int add = pow(2, bit); // bit value to add
    for (auto &r: rev) ans.push_back(r + add);
}

vector<int> Solution::grayCode(int A) {
    vector<int> ans;
    ans.push_back(0);
    for (int i=0; i<A; i++) process(i, ans);
    return ans;
}

// Solution 2, with out recursion

vector<int> Solution::grayCode(int A) {    
    vector<int> ans;
    ans.push_back(0);
    
    for (int i=0;i<A;i++) {
        vector<int> rev = ans;
        reverse(rev.begin(), rev.end());
        int add = pow(2,i);
        for (auto &r: rev)
            ans.push_back(r + add);
    }
    return ans;
}
