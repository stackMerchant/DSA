# [LC 847] Shortest Path Visiting All Nodes

```cpp
class Solution {
public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int n = graph.size();
        if (n==1) return 0;
        queue<pair<int, int>> q;
        int finalMask = (1<<n) - 1;
        vector<vector<bool>> visited(n, vector<bool>(finalMask+1, 0));

        for (int i=0; i<n; i++) {
            int node = i;
            int mask = 1<<i;
            q.push({node, mask});
            visited[node][mask] = 1;
        }
        
        int step = 0;
        while (!q.empty()) {
            step++;
            int size = q.size();
            while (size > 0) {
                auto [frontNode, frontMask] = q.front(); q.pop();

                for (auto &nbr: graph[frontNode]) {
                    int newMask = frontMask | 1<<nbr;
                    
                    if (newMask == finalMask) return step;

                    if (!visited[nbr][newMask]) {
                        visited[nbr][newMask] = true;
                        q.push({nbr, newMask});
                    }
                }
                size--;
            }
        }
        return -1;
    }
};
```