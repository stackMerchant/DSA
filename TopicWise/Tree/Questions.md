# Questions


## Trie
- [LC 212] Word Search 2
- [LC 642] Design Search Autocomplete System

## AVL tree
- Practice with this [link](https://www.geeksforgeeks.org/dsa/insertion-in-an-avl-tree/)

## Segment Tree & Fenwick Tree (BIT) Time Complexity comparison

| Operation    | Segment Tree        | Fenwick Tree (BIT)                      |
| ------------ | ------------------- | --------------------------------------- |
| Build        | **O(n)**            | **O(n)** (optimized) / O(n log n) naive |
| Point Update | **O(log n)**        | **O(log n)**                            |
| Range Query  | **O(log n)**        | **O(log n)**                            |
| Range Update | **O(log n)** (lazy) | **O(log n)** (using 2 BITs)             |
| Space        | **O(4n)**           | **O(n)**                                |
