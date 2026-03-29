# All triplets

- count and print
- [Question Link](https://leetcode.com/discuss/post/6205671/interview-qsn-faang-by-anonymous_user-d4gm/)
- [Same question again](https://leetcode.com/discuss/post/5967505/google-onsite-count-valid-triples-with-a-zj8v/)

## Solution
- Merge all elements with their original array id
- Maintain a sliding window till r-l<=d
- On addition of each element, check its array id and add other 2 array's count product
- Add current element to multiset


```cpp
long long solve(vector<int>& A, vector<int>& B, vector<int>& C, int D) {
    vector<pair<int,int>> X; // {value, type}
    
    for (auto x : A) X.push_back({x, 0});
    for (auto x : B) X.push_back({x, 1});
    for (auto x : C) X.push_back({x, 2});

    sort(X.begin(), X.end());

    long long ans = 0;

    int l = 0;
    long long cntA = 0, cntB = 0, cntC = 0;

    for (int r = 0; r < X.size(); r++) {
        int val = X[r].first;
        int type = X[r].second;

        // include current
        if (type == 0) cntA++;
        else if (type == 1) cntB++;
        else cntC++;

        // shrink window
        while (val - X[l].first > D) {
            if (X[l].second == 0) cntA--;
            else if (X[l].second == 1) cntB--;
            else cntC--;
            l++;
        }

        // count new triplets
        if (type == 0) ans += cntB * cntC;
        else if (type == 1) ans += cntA * cntC;
        else ans += cntA * cntB;
    }

    return ans;
}
```