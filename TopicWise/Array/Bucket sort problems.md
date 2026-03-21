# Bucket sort problems

## Leetcode 220

- Bucket sort, O(n + k)
- Leetcode 220
    - nearby almost duplicate problems
    - sliding window similarity detection
    - Solution 1 => ordered set / AVL tree, TC => n*log(k)
    - Solution 2 => inspired by Bucket Sort
        - Width of bucket = k + 1
        - Check in adjacent buckets
        - To handle negative numbers = (num + 1) / (k + 1)


## Another Question

- You’re given an endless stream of integers and a non-negative threshold d; your job is to pull off three numbers as soon as they “fit together,” meaning the difference between the smallest and largest of the three is at most d, discard those three so they can’t be reused, and continue until the stream ends, returning the list of all triplets in the order they were completed

- d = 2
- inputStream: [10, 5, 7, 6, 8, 3, 4, 1, 2]
- Result - [[5, 6, 7], [1, 2, 3]]

Solution 1 =>
Save a sorted set (AVL tree), at each addition check
1. prev 2
2. next 2
3. 1 prev and 1 next

Solution 2 =>
Solve by buckets in O(n), each triplet in O(1)
Each bucket will have at max 2 elements, compare it with adjacent bukets, in constant time we can get triplet
DS can be map of bucket id to 2 numbers
