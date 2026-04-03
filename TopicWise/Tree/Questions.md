# Questions

## Basic Trees
- [LC 687] Longest Univalue Path
- [LC 437] Path Sum III

## Misc
- Serialize Deserialize
    - save null pointers, to know when to return in recursion
    - Level Order, BFS
    - Preorder DFS

## Trie
- [LC 212] Word Search 2
- [LC 642] Design Search Autocomplete System
- [2 Good Questions](https://leetcode.com/discuss/post/5722000/google-onsite-questions-by-anonymous_use-3vg2/)

## AVL tree
- Practice with this [link](https://www.geeksforgeeks.org/dsa/insertion-in-an-avl-tree/)
- Insertion deletion and TCs

## Segment Tree & Fenwick Tree (BIT) Time Complexity comparison

| Operation    | Segment Tree        | Fenwick Tree (BIT)                      |
| ------------ | ------------------- | --------------------------------------- |
| Build        | **O(n)**            | **O(n)** (optimized) / O(n log n) naive |
| Point Update | **O(log n)**        | **O(log n)**                            |
| Range Query  | **O(log n)**        | **O(log n)**                            |
| Range Update | **O(log n)** (lazy) | **O(log n)** (using 2 BITs)             |
| Space        | **O(4n)**           | **O(n)**                                |
