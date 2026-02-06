// https://www.interviewbit.com/problems/cycle-in-directed-graph/

/************ Solution 1 ************/
// Using DFS or coloring

bool trav(vector<int> &visited, vector<vector<int>> &adj, int node) {
    // Completely visited
    if (visited[node] == 1) return false;
    // In rec stack, so cycle exists
    if (visited[node] == 0) return true;
    
    // Mark current node in recursion stack
    visited[node] = 0;
    // Visit adjacent nodes
    for (auto n: adj[node]) if (trav(visited, adj, n)) return true;
    // Mark current node completely visited
    visited[node] = 1;
    // No cylcle from this node
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // Create adjacency matrix
    vector<vector<int>> adj(A);
    for (auto b: B) adj[b[0]-1].push_back(b[1]-1);
    
    // Store visited states, also called colors/coloring
    // -1 => unvisited, 0 => in recursion stack, 1 => completely visited
    vector<int> visited(A, -1);
    
    // Check cycle from all nodes
    for (int i=0; i<A; i++) if (trav(visited, adj, i)) return true;
    return false;
}

/************ Solution 2 ************/
// Using Kahn's algo of topological sort

int Solution::solve(int A, vector<vector<int> > &B) {
    // Create adjacency matrix and store in degrees of all nodes
    vector<vector<int>> adj(A);
    vector<int> inDegree(A, 0);
    for (auto b: B) {
        adj[b[0]-1].push_back(b[1]-1);
        inDegree[b[1]-1]++;
    }
    
    // Put nodes with 0 inDegree in queue
    queue<int> q;
    for (int i=0; i<A; i++) if (inDegree[i] == 0) q.push(i);
    
    // Remove nodes with 0 inDegree
    vector<int> removedNodes(A, 0);
    int front;
    while (!q.empty()) {
        // Remove nodes with 0 inDegree
        front = q.front(); q.pop();
        removedNodes[front] = 1;
        
        // Decrease inDegree of adjacent nodes
        // And put nodes with 0 inDegree in queue
        for (auto a: adj[front]) {
            inDegree[a]--;
            if (inDegree[a] == 0) q.push(a);
        }
    }
    
    // If any node is not removed, then cycle exists
    for (auto rn: removedNodes) if (rn == 0) return true;
    return false;
}