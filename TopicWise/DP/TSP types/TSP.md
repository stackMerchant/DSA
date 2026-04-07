# TSP

```cpp
#include <bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>>& dist) {
    int n = dist.size();
    int N = 1 << n;

    vector<vector<int>> dp(N, vector<int>(n, INT_MAX));

    // Base case: start from city 0
    dp[1][0] = 0;

    // Iterate over all masks
    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            if (dp[mask][u] == INT_MAX) continue;

            // Try going to next city v
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;

                int newMask = mask | (1 << v);
                dp[newMask][v] = min(
                    dp[newMask][v],
                    dp[mask][u] + dist[u][v]
                );
            }
        }
    }

    // Complete cycle (return to 0)
    int ans = INT_MAX;
    int full = (1 << n) - 1;

    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[full][i] + dist[i][0]);
    }

    return ans;
}
```