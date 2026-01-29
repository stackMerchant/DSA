// https://www.interviewbit.com/problems/longest-substring-without-repeat/

int Solution::lengthOfLongestSubstring(string A) {
    unordered_set<char> set;
    int i = 0, j = 0, ret = 0;
    while (i < A.size()) {
        if (set.find(A[i]) == set.end()) {
            ret = max(ret, i - j + 1);
            set.insert(A[i]);
            i++;
        } else {
            set.erase(A[j]);
            j++;
        }
    }
    return ret;
}
