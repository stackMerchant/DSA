// https://www.interviewbit.com/problems/rod-cutting/

#define ll long long int

ll findCost(vector<vector<ll>> &costDP, vector<vector<int>> &indexDP, vector<ll> &cuts, int startIndex, int endIndex) {
    
    // If costDP is already present
    if(costDP[startIndex][endIndex] != -1) return costDP[startIndex][endIndex];
    
    // If indexes are bad
    if (startIndex + 1 >= endIndex) {
        costDP[startIndex][endIndex] = 0;
        return 0;
    }
    
    int minIndex = -1;
    ll minCost = -1, currCost;
    for (int i = startIndex + 1; i < endIndex; i++) {
        currCost = findCost(costDP, indexDP, cuts, startIndex, i) + findCost(costDP, indexDP, cuts, i, endIndex);
        if (minIndex == -1) {
            minCost = currCost;
            minIndex = i;
        } else if (currCost < minCost) {
            minCost = currCost;
            minIndex = i;
        }
    }
    
    indexDP[startIndex][endIndex] = minIndex;
    costDP[startIndex][endIndex] = minCost + cuts[endIndex] - cuts[startIndex];
    return costDP[startIndex][endIndex];
}

void findOrder(vector<int> &ret, vector<vector<int>> &indexDP, vector<ll> &cuts, int startIndex, int endIndex) {
    int minIndex = indexDP[startIndex][endIndex];
    if (minIndex != -1) {
        ret.push_back(cuts[minIndex]);
        findOrder(ret, indexDP, cuts, startIndex, minIndex);
        findOrder(ret, indexDP, cuts, minIndex, endIndex);
    }
    return;
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    // Prepare cuts array
    vector<ll> cuts;
    cuts.push_back(0);
    for(auto b: B) cuts.push_back(b);
    cuts.push_back(A);
    sort(cuts.begin(), cuts.end());
    int n = cuts.size();
    
    vector<vector<ll>> costDP(n, vector<ll>(n, -1));
    vector<vector<int>> indexDP(n, vector<int>(n, -1));
    
    findCost(costDP, indexDP, cuts, 0, n-1); // Prepare costDP and indexDP
    vector<int> ret;
    findOrder(ret, indexDP, cuts, 0, n-1);
    
    return ret;
}