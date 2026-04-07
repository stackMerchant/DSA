# DP questions

# Lesson
- LIS in nlogn
- Distinct Subsequences, [LC 940] [LC 1987]
- 1D take/leave, [LC 1235]
- [LC 727]

## Done
- LIS
    - Standard => n^2
    - Optimized => nlog(n)
    - [LC 354] Russian Doll Envelopes
    - Sort by increasing width and decreasing height, then take heights out and do LIS on them
- Distinct Subsequences
    - [LC 940] Distinct Subsequences II
    - [LC 1987] Number of Unique Good Subsequences (only binary chars)
- [LC 416] Partition Equal Subset Sum
    - n * max(ni)
- *[LC 1235] Maximum Profit in Job Scheduling
    - Sort by start/end, then leave or take (find next by Binary Search)
    - TC => nlog(n)
- Paint House
    - [LC 256] Paint House, TC => O(n)
    - [LC 265] Paint House II, TC => O(n * k^2) => improved to => O(n * k)
- Subsequence DP problem
    - [Link](https://leetcode.com/discuss/post/6934675/google-recent-dp-count-subsequences-vari-m22y/)
    - Solve it by n X 4 dp table, 4 states being => 1even, 2even, 1odd, 2odd
- LC 392, then LC 792
    - pub-sub, TC => n * words

## To be or not be
- [LC 2184] Number of Ways to Build Sturdy Brick Wall
    - Generate all combinations, 2^(width) ~ n
        - 2^(number of elements), number of elements at max will be width, because there is a brick with width 1
    - Build compatibility adjacency
    - Do dp, for each height i, dp[i][pattern] = sum of (dp[i-1][compatible pattern])
- [LC 2407] LIS II
    - Segment tree
    - TC => nlog(n)
- [LC 10] Regular Expression Matching
    - Good question
- [LC 2035] Partition Array Into Two Arrays to Minimize Sum Difference
    - Not 2D matrix, because constraints are high
    - Recursive, no dp
- [LC 975] Odd Even Jump
    - O(nlogn) + O(n) // good question
    - Similar question [Link](https://leetcode.com/discuss/post/4878831/google-onsite-question-by-anonymous_user-ki2t/)
        - Maintain sorted set/tree for whole tree array
        - If you reach same index with same move direction, then infinite cycle
        - TC => (2n) * log(n) // 2n because n positions and for each position 2 directions
- [LC 727] Minimum Window Subsequence
    - Good question
    - See approach [here](https://www.hellointerview.com/learn/code/dynamic-programming/minimum-window-subsequence)
    - TC => O(mn)
- [LC 1092] take code from AI, good solution, do
    - Find LCS, and create DP table
    - Then trace the max dp path from (n,m)

## Shortest common superstring
- [Shortest Common Superstring (on Interviewbit)](https://www.interviewbit.com/problems/shortest-common-superstring/)
- [LC 943] Shortest common superstring // not done, attempted

## Not done
- [LC 3287] Find the Maximum Sequence Value of Array
- [LC 2338] Count the Number of Ideal Arrays
- [LC 3149] Find the Minimum Cost Array Permutation
