// https://www.interviewbit.com/problems/cycle-in-undirected-graph/

/************ Solution 1 ************/
// Using DFS

bool trav(vector<vector<int>> &adj, vector<int> &visited, int currNode, int parentNode) {
    // If currNode is already visited, then cycle exists
    if (visited[currNode] == 1) return true;
    
    // Mark currNode visited
    visited[currNode] = 1;
    // Visit adjacent nodes, except parentNode
    for (auto a: adj[currNode])
        if (a != parentNode && trav(adj, visited, a, currNode)) return true;
        
    // No cycle from currNode
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // Create adjacency matrix
    vector<vector<int>> adj(A);
    for (auto b: B) {
        adj[b[0] - 1].push_back(b[1] - 1);
        adj[b[1] - 1].push_back(b[0] - 1);
    }
    
    // Visit all unvisited nodes
    vector<int> visited(A, 0);
    for (int i=0; i<A; i++) 
        if (visited[i] == 0 && trav(adj, visited, i, -1)) return true;
    return false;
}

/************ Solution 2 ************/
// Using disjoint sets

int findParent(vector<int> &parentNode, int x) {
    // If parent == node, it is the root of set
    if (parentNode[x] == x) return x;
    // Find parent and do path compression
    parentNode[x] = findParent(parentNode, parentNode[x]);
    return parentNode[x];
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // Store parent and rank of each node
    // Parent of each node will be itself initially
    // Rank is initially 1 of each node and increases upon addtion of nodes under it
    vector<int> parentNode(A), rank(A, 1);
    for (int i=0; i<A; i++) parentNode[i] = i;
    
    // x, y => nodes
    // px, py => parent nodes of x and y
    int x, y, px, py;
    for (auto b: B) {
        x = b[0] - 1;
        y = b[1] - 1;
        
        px = findParent(parentNode, x);
        py = findParent(parentNode, y);
        // If parents are same, they are already in a set, cycle exists
        if (px == py) return 1;

        if (rank[px] >= rank[py]) {
            // px becomes parent of py
            parentNode[py] = px;
            rank[px] += rank[py];
        } else {
            // py becomes parent of px
            parentNode[px] = py;
            rank[py] += rank[px];
        }
    }

    // No cycle found
    return 0;
}
