// https://www.interviewbit.com/problems/path-with-good-nodes/

void trav(int node, int C, int &ans, vector<int> &visited, vector<vector<int>> &adj, vector<int> &isGood) {
    // handle if visited
    if (visited[node] == 1) return;
    visited[node] = 1;
    
    // if good node, count it
    if (isGood[node]) C--;
    if (C < 0) return;
    
    // if only one adjacent node, and that is visited too, then it is a leaf node
    if (adj[node].size() == 1 && visited[adj[node][0]]) {
        ans++;
        return;
    }
    
    // go deeper in tree
    for (auto &_adj: adj[node]) {
        trav(_adj, C, ans, visited, adj, isGood);
    }
}

int Solution::solve(vector<int> &isGood, vector<vector<int>> &edges, int C) {
    int n = isGood.size();
    vector<vector<int>> adj(n);
    for (auto &e: edges) {
        adj[e[0]-1].push_back(e[1]-1);
        adj[e[1]-1].push_back(e[0]-1);
    }
    
    vector<int> visited(n, 0);
    int ans = 0;
    trav(0, C, ans, visited, adj, isGood);
    return ans;
}
