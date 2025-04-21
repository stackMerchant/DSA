// https://www.interviewbit.com/problems/2-sum/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int, int> map;
    for (int i=0; i<A.size(); i++) {
        int ai = A[i];
        if (map.find(B - ai) != map.end()) {
            return {map[B - ai], i+1};
        }
        if (map.find(ai) == map.end()) map[ai] = i + 1;
    }
    return {};
}
