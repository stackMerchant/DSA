# Notes

## Misc

#### Minimum spanning tree
- Kruskal's algo: Sort all edges upfront
  - find minimum spanning tree
  - sort edges by weight
  - keep picking the smallest edges and merge them with disjoint set
- Prim's algo: Use a min-heap to pick smallest edge dynamically (“sorting on the fly”)
  - same as above but sort on fly

#### Word ladder 1 & 2
- 2 key ideas:
  - do BFS
  - get next values nodes intelligently, i.e., compare changing characters or a linear scan
- Do bfs via Queue OR recursive with removing next nodes and then going into recursion

#### Cycles in graphs
- Undirected graph
  - Disjoint set
  - If found a visited non parent, then cycle exists, simple code for this too
- Directed graph
  - Topological sort, or
  - Coloring with 3 colors
- All simple cycles in Directed Graph
  - Johnson's algo
    - Separate all SCCs, then detect all cycles from each node one by one

#### Kosaraju's algo for SCCs
- TC => O(V+E)

# Questions

- [LC 2203] Minimum Weighted Subgraph With the Required Paths
  - Dijkstra from s1, s2, dest to all
  - Minimize, dist(n, s1) + dist(n, s2) + dist(n, dest)
- [LC 2115] Find All Possible Recipes from Given Supplies
  - Topological sort
- [LC 778] Swim in Rising Water
  - Dijksta => nlog(n), n is n^2
  - Union Find => n, so union find, n is n^2, and sorting too so (n^2)log(n)
  - Can do binary search on limits and check reachability, still (n^2)log(n)
- [LC 2812] Find the Safest Path in a Grid
  - Multi source BFS + sort + Union find (DSU)
  - Multi source BFS + DFS
  - TC => n^2*log(n)
- [LC 2360] Longest Cycle in a Graph
  - Topological trimming
  - Then just visit every node and on finding a visited, calculate cycle length
- [LC 417] Pacific Atlantic Water Flow
  - DFS from edges
  - TC => O(mn)
- [LC 1970] Last Day Where You Can Still Cross
  - S1 => Binary Serach + BFS/DFS, TC => (mn)log(mn)
  - S2 => Union Find of left edge and right edge, TC => mn
- Interview Question
  - [OA Q2 in here](https://leetcode.com/discuss/post/7291253/google-swe-summer-intern-2026-july-2025-2qbq3/)
  - Create disjoint sets by joining elements if they share a prime factor
- [LC 815] Bus Routes
  - Do it
  - TC => O(m * n)

## DFS
- [LC 694] Distinct islands
- [LC 711] Distinct islands 2
- [LC 2065] Maximum Path Quality of a Graph
- Interview Question
  - [Link](https://leetcode.com/discuss/post/6759221/google-swe-phone-screen-l3-by-anonymous_-hhgm/)
  - Find connected components, then check are they square
  - TC => O(mn)
- [LC 3481] Apply Substitutions
  - Recursively simplify strings
  - TC => nl + kl
    - n is length of original string to be replaced with k -> v
    - k is all the keys
    - l is avg length of value strings
- [LC 1568] Minimum Number of Days to Disconnect Island
  - Mid-good question
  - Check if already disconnected, then 0
  - Check if removing one will disconnect, then 1
    - Try removing each cell and checking disconnection
  - Else 2
  - TC => O((mn)^2)

## BFS
- [LC 773] Sliding Puzzle
- Multi source BFS or sweep in 4 directions
  - [LC 542] 01 Matrix
  - [LC 1765] Map of Highest Peak

## Bipartite Grpah
- [LC 785] Is Graph Bipartite?
- [LC 886] Possible Bipartition
- [LC 2493] Divide Nodes Into the Maximum Number of Groups
  - Start from every node and try to assign group numbers
  - TC => O(n * (n + m))
- [LC 1042] Flower Planting With No Adjacent
  - [Link](https://www.youtube.com/watch?v=wuVwUK25Rfc)
