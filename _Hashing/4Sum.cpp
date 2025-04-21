// https://www.interviewbit.com/problems/4-sum/

vector<vector<int>> Solution::fourSum(vector<int> &A, int B) {
    int n = A.size();
    // Sort so that when we add elements they are in order
    sort(A.begin(), A.end());
    
    // Sum of pair to list of pairs in sorted order
    unordered_map<int, set<pair<int, int>>> map;
    // Sorted quadruplets
    set<vector<int>> ret;
    
    // This i acts as separator of list
    // First part's all pairs are in map, second part is explored
    for (int i=0; i<n; i++) {
        // Element 3 => i, Element 4 => i+1 to n-1
        for (int j=i+1; j<n; j++) {
            int reqPairSum = B - A[i] - A[j];
            if (map.find(reqPairSum) != map.end()) {
                set<pair<int, int>> pairs = map[reqPairSum];
                for (auto &p: pairs) {
                    ret.insert({p.first, p.second, A[i], A[j]});
                }
            }
        }
        // Add all previous pairs with i
        // Element 1 => 0 to i-1, Element 2 => i
        for (int j=0; j<i; j++) map[A[j] + A[i]].insert({A[j], A[i]});
    }
    return vector<vector<int>>(ret.begin(), ret.end());
}
