// https://www.interviewbit.com/problems/useful-extra-edges/

void dijk(int start, vector<vector<pair<int, int>>> &adj, vector<int> &dist) {
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [currDist, currNode] = pq.top(); pq.pop();
        
        for (auto [nextNode, distance]: adj[currNode]) {
            if (dist[nextNode] == -1 || dist[nextNode] > dist[currNode] + distance) {
                dist[nextNode] = dist[currNode] + distance;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

int Solution::solve(int A, vector<vector<int> > &B, int src, int dest, vector<vector<int> > &E) {
    
    // prepare adjacency lists
    vector<vector<pair<int, int>>> adj(A+1);
    
    int f, t, d;
    for (auto &b: B) {
        // from f to t with distance d
        f = b[0];
        t = b[1];
        d = b[2];
        adj[f].push_back({t, d});
        adj[t].push_back({f, d});
    }
    
    // calculate distances of each node from src and dest
    vector<int> distToSrc(A+1, -1);
    vector<int> distToDest(A+1, -1);
    
    dijk(src, adj, distToSrc);
    dijk(dest, adj, distToDest);
    
    // distance to destination without selecting any node from E
    int ret = distToSrc[dest];
    
    // replace by each element of E one by one
    for (auto &e: E) {
        // from f to t with distance d
        f = e[0];
        t = e[1];
        d = e[2];
        int d1 = distToSrc[f] + d + distToDest[t];
        int d2 = distToSrc[t] + d + distToDest[f];
        ret = min({ret, d1, d2});
    }
    return ret;
}
