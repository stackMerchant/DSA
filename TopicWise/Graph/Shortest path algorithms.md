# Shortest path algos

#### BFS
- if no weights

#### Dijkstra
- store cost while popping
- works only with positive weights
- for negative weights
  - Bellman–Ford, O(VE)
  - Floyd Warshall, O(V^3)
- constrained dijkstras, (save costs and some states):
  - Limited stops/hops	(cost, node, stops)
  - Fuel constraints	(cost, node, fuel_left)
  - Must-visit checkpoints	(cost, node, visited_mask)
  - Time windows	(cost, node, arrival_time)

#### Bellman–Ford, O(VE)
- if dist[v] > dist[u] + w, then update dist and parent
- do it V-1 times, and once more, if it reduces further then a negative weight cycle exists 
- TC => O(VE)
- if want to calculate for every node pair, TC will become O(V^2 * E) or O(V^4), Floyd warshall does it better
- works for both directed and undirected graphs, but in undirected graphs, a single negative edge forms a negative cycle, so negative-weight cases are only meaningful in directed graphs
- [LC 743] Network Delay Time

#### Floyd Warshall, O(V^3)
- computes all-pairs shortest paths using DP
- store distance matrix and a path matrix
- loop over ijk, and do following
```c++
for ijk:
if (dist[i][k] != INF && dist[k][j] != INF) {
  if (dist[i][j] > dist[i][k] + dist[k][j]) {
    // Distance update
    dist[i][j] = dist[i][k] + dist[k][j];
    
    // Path update
    path[i][j] = path[k][j];
    // OR
    path[i][j] = path[i][k];
  }
}
```
- if diagonal distance in distance matrix is negative, then negative cycle exists
- and for undirected graphs, same issue as Bellman-Ford
- [LC 1334] Find the City With the Smallest Number of Neighbors at a Threshold Distance

## Questions
- [LC 787] Cheapest Flights Within K Stops
  - Dijkstra with stops as part of state
    - TC => kElog(kV)
    - SC => kV
  - Bellman-ford, k+1 iterations // NOT DONE
    - TC => kE
    - SC => V
