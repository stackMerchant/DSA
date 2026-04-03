# [LC 1192] Critical Connections in a Network

```cpp
class Solution {
public:
    
    void dfs(int currentNode, int parentNode, vector<vector<int>> &adj, int &time, vector<int> &discovery, vector<int> &lowest, vector<vector<int>> &bridges) {
        discovery[currentNode] = lowest[currentNode] = time; time++;

        for (auto &neighbor: adj[currentNode]) {
            if (neighbor == parentNode) continue;

            if (discovery[neighbor] == -1) {
                dfs(neighbor, currentNode, adj, time, discovery, lowest, bridges);
                
                lowest[currentNode] = min(lowest[currentNode], lowest[neighbor]);

                if (discovery[currentNode] < lowest[neighbor]) {
                    bridges.push_back({currentNode, neighbor});
                }
            } else {
                lowest[currentNode] = min(lowest[currentNode], lowest[neighbor]);
            }
        }   
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // create adj
        vector<vector<int>> adj(n);
        for (auto &c: connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        int time = 0;
        vector<int> discovery(n, -1);
        vector<int> lowest(n, -1);

        vector<vector<int>> bridges;
        dfs(0, -1, adj, time, discovery, lowest, bridges);
        return bridges;
    }

};
```