// https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/

// Solution:
// 1. Maintain left sum and find current left sum in a map
// 2. If found it means sum from there to here is same

#define ll long long

vector<int> Solution::lszero(vector<int> &A) {
    int n = A.size();
    // Calculate sum of values in left
    vector<ll> leftSum;
    ll sum = 0;
    for (int i=0; i<n; i++) {
        sum += A[i];
        leftSum.push_back(sum);
    }
    
    // Map of leftSum to first index at which that leftSum was found
    unordered_map<ll, int> map;
    // To cover edge case
    map[0] = -1;
    int a = 0, b = 0, maxLength = -1, currLength;
    
    for (int i=0; i<n; i++) {
        // If leftSum is not present, just add it
        if (map.find(leftSum[i]) == map.end()) {
            map[leftSum[i]] = i;
        } else {
            // Else calculate length of current sequence
            currLength = i - map[leftSum[i]];
            if (currLength > maxLength) {
                maxLength = currLength;
                a = map[leftSum[i]];
                b = i;
            }
        }
    }
    
    // Create subsequence and return
    vector<int> ret;
    for (int i=a+1; i<=b; i++) ret.push_back(A[i]);
    return ret;
}
