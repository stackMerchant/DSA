// https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/

void dfs(vector<vector<int>> &adj, vector<int> &visited, int &farthestNode, int &farthestDist, int currNode, int currDist) {
    // If visited, skip, else mark visited
    if (visited[currNode] == 1) return;
    visited[currNode] = 1;
    
    // Visit adjacent nodes
    for (auto adjNode: adj[currNode]) 
        dfs(adj, visited, farthestNode, farthestDist, adjNode, currDist + 1);
    
    // Set farthese node/distance
    if (currDist > farthestDist) {
        farthestDist = currDist;
        farthestNode = currNode;
    }

    return;
}

int Solution::solve(vector<int> &A){
    // Initialize adjacency matrix
    int n = A.size();
    vector<vector<int>> adj(n);
    for(int i=1; i<n; i++) {
        adj[i].push_back(A[i]);
        adj[A[i]].push_back(i);
    }

    // Calculate farthest node/distance from any node (take 0), say farthest node found is NODE1
    int srcNode = 0, farthestNode = 0, farthestDist = 0;
    vector<int> visited(n, 0);
    dfs(adj, visited, farthestNode, farthestDist, srcNode, 0);
    
    // Calculate farthest node/distance from NODE1, distance will be tree width
    srcNode = farthestNode;
    visited = vector<int>(n, 0);
    dfs(adj, visited, farthestNode, farthestDist, srcNode, 0);
    
    return farthestDist;
}