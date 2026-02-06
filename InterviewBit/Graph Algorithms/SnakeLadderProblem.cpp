// https://www.interviewbit.com/problems/snake-ladder-problem/

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    unordered_map<int, int> transfer;
    for (auto &a: A) transfer[a[0]] = a[1];
    for (auto &b: B) transfer[b[0]] = b[1];
    
    vector<int> visited(101, 0);
    queue<pair<int, int>> q;
    visited[1] = 1;
    q.push({1, 0});
    
    while (!q.empty()) {
        // extract current node details
        auto [currNode, currRollCount] = q.front(); q.pop();
        
        // explore all reachable nodes by dice
        for (int i=1; i<=6; i++) {
            int nextNode = currNode + i;
            if (nextNode > 100) continue;
            
            if (!visited[nextNode]) { // if not visited
                visited[nextNode] = 1; // mark visited
                
                // if has transfer, and transfer destination node is not visited
                if (transfer.find(nextNode) != transfer.end() && !visited[transfer[nextNode]]) {
                    nextNode = transfer[nextNode];
                    visited[nextNode] = 1; // mark visited
                }
                
                q.push({nextNode, currRollCount + 1});
            }
            
            if (nextNode == 100) return currRollCount + 1; // do it here so that transfer is considered
        }   
    }
    
    return -1;
}
