// https://www.interviewbit.com/problems/delete-edge/

// Solution: Calculate sum of all tree and subtract it from sub tree sum

typedef unsigned long long ull;

// traverse and return sum of sub tree
ull trav(int node, ull &treeSum, ull &ans, vector<int> &visited, vector<int> &weights, vector<vector<int>> &adj) {
    if (visited[node]) return 0;
    visited[node] = 1;
    
    ull childSum, prod, subTreeSum = weights[node];
    for (auto child: adj[node]) {
        childSum = trav(child, treeSum, ans, visited, weights, adj);
        subTreeSum += childSum;
        
        prod = childSum * (treeSum - childSum);
        ans = max(ans, prod);
    }
    return subTreeSum;
}

int Solution::deleteEdge(vector<int> &weights, vector<vector<int> > &edges) {
    int n = weights.size();
    
    // calculate sum of complete tree
    ull treeSum = 0;
    for (auto weight: weights) treeSum += weight;
    
    // create adjacency
    vector<vector<int>> adj(n);
    for (auto edge: edges) {
        adj[edge[0]-1].push_back(edge[1]-1);
        adj[edge[1]-1].push_back(edge[0]-1);
    }
    
    ull ans = 0, mod = 1000000007;
    vector<int> visited(n, 0); // 0/1
    trav(0, treeSum, ans, visited, weights, adj);
    
    return ans % mod;
}
