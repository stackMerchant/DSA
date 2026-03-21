# Notes

## TSP
- Go from LC 847 to TSP, with AI through multiple approaches


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
  - Multi source BFS + sort + Union find (DSU)
  - Multi source BFS + DFS
- [LC 815] Bus Routes
- [LC 2360] Longest Cycle in a Graph
  - Topological trimming

## DFS
- [LC 694] Distinct islands
- [LC 711] Distinct islands 2

## BFS
- [LC 773] Sliding Puzzle
