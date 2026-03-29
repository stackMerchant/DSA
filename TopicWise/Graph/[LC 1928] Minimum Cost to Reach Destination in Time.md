# [LC 1928] Minimum Cost to Reach Destination in Time

## Solution 1
- Using Dijkstra
- State => `(node, fee, time)`, sorted on fees
- Visited is tracked with time, visit again with shorter time
- TC => `O(Etlog(Vt))`, t is `maxTime` // similar to `ElogV` of Dijkstra

```cpp
struct NodeInfo {
    int node;
    int fee;
    int time;

    NodeInfo(int n, int f, int t) {
        node = n;
        fee = f;
        time = t;
    }
};

class Compare {
    public:
        bool operator()(const NodeInfo &n1, const NodeInfo &n2) {
            return n1.fee > n2.fee;
        }
};

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        // Prepare adjacency
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e: edges) {
            int u = e[0], v = e[1], t = e[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        // Prepare visited
        vector<int> visitedTime(n, -1);

        // PQ of (fee, node)
        priority_queue<NodeInfo, vector<NodeInfo>, Compare> pq;
        pq.push(NodeInfo(0, passingFees[0], 0));

        while (!pq.empty()) {
            NodeInfo top = pq.top(); pq.pop();
            int node = top.node;
            int fee = top.fee;
            int time = top.time;

            if (time > maxTime) continue;
            if (node == n-1) return fee;

            if (visitedTime[node] == -1 || time < visitedTime[node]) {
                visitedTime[node] = time;
                for (auto &[nextNode, edgeTime]: adj[node]) {
                    int timeToNextNode = time + edgeTime;
                    int feeToNextNode = fee + passingFees[nextNode];
                    pq.push(NodeInfo(nextNode, feeToNextNode, timeToNextNode));
                }
            }
        }
        return -1;
    }
};
```

## Solution 2
- Using DP
- TC => `Et`

```cpp
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        int INF = 1 << 30;
        vector<vector<int>> dp(n, vector<int>(maxTime + 1, INF)); // value is cost
        dp[0][0] = passingFees[0];

        for (int t=1; t<=maxTime; t++) {
            for (auto &edge: edges) {
                int u = edge[0];
                int v = edge[1];
                int edgeTime = edge[2];

                if (edgeTime <= t) {    
                    dp[u][t] = min(dp[u][t], dp[v][t - edgeTime] + passingFees[u]);
                    dp[v][t] = min(dp[v][t], dp[u][t - edgeTime] + passingFees[v]);
                }
            }
        }

        int ans = INF;
        for (int t=0; t<=maxTime; t++) {
            ans = min(ans, dp[n-1][t]);
        }
        return (ans < INF) ? ans : -1;
    }
};
```