# Notes

## Shortest path algos

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


## Misc

#### Minimum spanning tree
- Kruskal's algo: Sort all edges upfront
  - find minimum spanning tree
  - osrt edges by weight
  - keep picking the smallest edges and merge them with disjoint set
- Prim's algo: Use a min-heap to pick smallest edge dynamically (“sorting on the fly”)
  - same as above but sort on fly

#### Word ladder 1 & 2
- 2 key ideas:
  - do BFS
  - get next values nodes intelligently, i.e., compare changing characters or a linear scan
- do bfs via Queue OR recursive with removing next nodes and then going into recursion

#### Cycles in graphs
- Undirected graph
  - Disjoint set
  - If found a visited non parent, then cycle exists, simple code for this too
- Directed graph
  - Topological sort, or
  - Coloring with 3 colors


# Questions

- [[LC 2203] Minimum Weighted Subgraph With the Required Paths](https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/description/)

- [LC 2115] Find All Possible Recipes from Given Supplies
  - Topological sort
- [LC 778] Swim in Rising Water
  - Dijksta => nlog(n)
  - Union Find => n, so union find
- [LC 2812] Find the Safest Path in a Grid
- [LC 815] Bus Routes

## DFS
- [LC 694] Distinct islands
- [LC 711] Distinct islands 2

