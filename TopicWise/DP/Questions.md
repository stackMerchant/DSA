# DP questions

## Done
- LIS
    - Standard => n^2
    - Optimized => nlog(n)
    - [LC 354] Russian Doll Envelopes
- Distinct Subsequences
    - [LC 940] Distinct Subsequences II
    - [LC 1987] Number of Unique Good Subsequences (only binary chars)
- [LC 416] Partition Equal Subset Sum
- [LC 1235] Maximum Profit in Job Scheduling
    - Sort by start/end, then leave or take (find next by Binary Search)
- Paint House
    - [LC 256] Paint House, TC => O(n)
    - [LC 265] Paint House II, TC => O(n * k^2) => improved to => O(n * k)
- Subsequence DP problem
    - [Link](https://leetcode.com/discuss/post/6934675/google-recent-dp-count-subsequences-vari-m22y/)
    - Solve it by n X 4 dp table, 4 states being => 1even, 2even, 1odd, 2odd

## To be or not be
- LC 392, then LC 792
- LC 2184
- LC 2407
- [LC 10] Regular Expression Matching
- [LC 943] Find the Shortest Superstring // not done, attempted
- [Shortest Common Superstring (on Interviewbit)](https://www.interviewbit.com/problems/shortest-common-superstring/)
- [LC 2035] Partition Array Into Two Arrays to Minimize Sum Difference
    - Not 2D matrix, because constraints are high
    - Recursive
- [LC 975] Odd Even Jump
    - O(nlogn) + O(n) // good question
    - Similar question [Link](https://leetcode.com/discuss/post/4878831/google-onsite-question-by-anonymous_user-ki2t/)
        - Maintain sorted set/tree for whole tree array
        - If you reache same index with same move direction, then infinite cycle
        - TC => (2n) * log(n) // 2n because n positions and for each position 2 directions
- [LC 727] Minimum Window Subsequence
    - Good question
    - See approach [here](https://www.hellointerview.com/learn/code/dynamic-programming/minimum-window-subsequence)
    - TC => O(mn)

## Do again
- LC 1092, take code from AI, good solution
- [LC 943] Shortest common superstring
- TSP

## Not done
- [LC 3287] Find the Maximum Sequence Value of Array
- [LC 2338] Count the Number of Ideal Arrays
- [LC 3149] Find the Minimum Cost Array Permutation
