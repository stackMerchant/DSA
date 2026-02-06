// https://www.interviewbit.com/problems/check-palindrome/

int Solution::solve(string A) {
    int N = A.size();
    unordered_map<char, int> m;
    
    for (auto a: A) {
        if(m.find(a) == m.end()) m[a] = 1;
        else m[a]++;
    }
    
    int oddCount = 0;
    for(auto _m: m) {
        if(_m.second & 1) oddCount++;
    }
    return oddCount > 1 ? 0 : 1;
}
