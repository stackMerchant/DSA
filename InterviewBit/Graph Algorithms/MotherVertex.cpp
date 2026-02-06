// https://www.interviewbit.com/problems/mother-vertex/

/************ Solution 1 ************/
// Derived from Kosaraju's Algorithm for Strongly Connected Components

// Algo:
// 1. find unvisited node, this node becomes potential mother vertex
// 2. visit all (dfs) from that node
// 3. repeat 1-2, till al nodes are visited
// 4. visit all from last potential mother vertex
// 5. if all visited, then mother vertex is correct, else doesn't exists

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true; // visit node
    
    // traverse adjacent
    for (auto a: adj[node]) {
        if (!visited[a]) {
            dfs(a, adj, visited);
        }
    }
}

int Solution::motherVertex(int A, vector<vector<int> > &B) {
    // Create adjacency lists
    vector<vector<int>> adj(A);
    for (auto b: B) adj[b[0]-1].push_back(b[1]-1); // making nodes 0 indexed
    
    vector<bool> visited(A, false); // to track visited nodes
    int mother; // mother vertex candidates
    for (int i=0; i<A; i++) {
        if (!visited[i]) { // if not visited
            mother = i; // current node becomes potential mother vertex
            dfs(i, adj, visited); // visit all from this node
        }
    }
    
    visited.clear(); visited.resize(A, false); // reset visited
    dfs(mother, adj, visited); // dfs from mother vertex
    
    for (auto v: visited) if (!v) return 0;
    return 1;
}

/************ Solution 2 ************/

// If we want to just check if a mother vertex exists, then:
// 1. Check if all nodes are connected, treating directed graph as undirected graph
// 2. Calculate inDegree of all nodes
// 3. If count of nodes with 0 inDegree is less than 2, then mother vertex exists
