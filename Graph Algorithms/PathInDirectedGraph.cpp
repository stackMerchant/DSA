// https://www.interviewbit.com/problems/path-in-directed-graph/

// Need to pass graph with reference, otherwise a new graph is created on each call
// s => source, d => destination
int check(int s, int &d, vector<vector<int>> &adj, vector<bool> &visited) {
    // Already visited will not have a path to destination
    if (visited[s]) return 0;
    
    // Mark visited
    visited[s] = true;
    
    // If reached
    if (s == d) return 1;
    
    // Check adjacent nodes
    for (auto n: adj[s]) {
        if (check(n, d, adj, visited)) return 1;
    }
    
    // Not found
    return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // Create adjacency matrix
    vector<vector<int>> adj(A+1);
    for (auto b: B) adj[b[0]].push_back(b[1]);
    
    vector<bool> visited(A+1, false);
    return check(1, A, adj, visited);
}
