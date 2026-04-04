# Articulation in Graph

- If practicing, do articulation edge/bridge first then articulation point
- Edge's code is simple and easy to understand, modify it for vertex/point

## 1. Articulation edge or bridge
- [LC 1192] Critical Connections in a Network

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
                lowest[currentNode] = min(lowest[currentNode], discovery[neighbor]);
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

## 2. Articulation point/vertex

```cpp
class Solution {
public:
    
    void dfs(int currentNode, int parentNode, vector<vector<int>> &adj, int &time, vector<int> &discovery, vector<int> &lowest, vector<int> &points) {
        discovery[currentNode] = lowest[currentNode] = time; time++;
        
        int childCount = 0; // for root check

        for (auto &neighbor: adj[currentNode]) {
            if (neighbor == parentNode) continue;

            if (discovery[neighbor] == -1) {
                childCount++; // for root check

                dfs(neighbor, currentNode, adj, time, discovery, lowest, bridges);
                
                lowest[currentNode] = min(lowest[currentNode], lowest[neighbor]);

                if (parentNode != -1 && discovery[currentNode] <= lowest[neighbor]) {
                    points.push_back(currentNode);
                }
            } else {
                lowest[currentNode] = min(lowest[currentNode], discovery[neighbor]);
            }
        }

        // check for root
        if (parentNode == -1 && childCount > 1) {
            points.push_back(currentNode);
        }
    }

    vector<int> criticalPoints(int n, vector<vector<int>>& connections) {
        // create adj
        vector<vector<int>> adj(n);
        for (auto &c: connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }

        int time = 0;
        vector<int> discovery(n, -1);
        vector<int> lowest(n, -1);

        vector<int> points;
        dfs(0, -1, adj, time, discovery, lowest, bridges);
        return points;
    }

};
```