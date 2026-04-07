# Two Pointers Questions

- Aggregated queries
    - [LC 3355] Zero Array Transformation I
    - [LC 3356] Zero Array Transformation I
    - [LC 995] Minimum Number of K Consecutive Bit Flips
        - O(n) solution greedy solution, flip as soon as you see
        - TC => nk, improve it to just n
        - Track flips by saving aggregate flips at each index
- [LC 11] Container With Most Water
    - TC => O(n)
- Rain water trapping in O(1) space
    - [LC 42] Trapping Rain Water
- [LC 647] Palindromic Substrings
    - TC => n^2, expand from middle
- [LC 777] Swap Adjacent in LR String
    - Check relative ordering and compare indexes of L & R in initial and final
    - Similar problem => [LC 2337] Move Pieces to Obtain a String
    - For followup in [this](https://leetcode.com/discuss/post/6649648/google-l3-phone-screen-round-by-anonymou-7935/)
        - Find the target string in original string by KMP, remove everything else, then do check like above

# Sliding Window Questions
- [LC 1423] Maximum Points You Can Obtain from Cards
    - Add array at the back and do sliding window
    - If no extra space, maintain 2 pointers
- [LC 3] Longest Substring Without Repeating Characters
    - TC => O(n)
    - Faster with slight improvement [here](https://www.hellointerview.com/learn/code/sliding-window/longest-substring-without-repeating-characters#alternate-faster-solution)
- [LC 424] Longest Repeating Character Replacement
    - Good question
    - Sliding window, expand untill maxFreq + k < window size
    - Then move the window right, keeping the size same
    - Update char to count map, but not maxFreq
- [LC 1918] Kth Smallest Subarray Sum
    - Binary search on sum, for each sum check feasibility
    - Check feasibility by sliding window
    - If values can be negative, [round 4 here](https://leetcode.com/discuss/post/6749643/google-l3-interview-experience-by-anonym-zbbq/)
        - Calculate prefix sum
        - For each prefix, check count in range (currPrefix - k, currPrefix)
        - Use balanced BST for above, Segment tree/ fenwick tree can be used too
- [LC 1004] Max Consecutive Ones III
    - Do not need to aggressively shrink, doesn't matter if we do too
- Interview question
    - [Round 3](https://leetcode.com/discuss/post/6634542/google-india-l5-by-anonymous_user-ji1t/)
    - Start from first, keep extending currnet segment for each number
    - If current number asks to extend beyond 5, new segment, GREEDY
- [LC 632] Smallest Range Covering Elements from K Lists
    - Merge all into one and do a sliding window
    - Also refer to all triplets in folder

# Intervals
- [LC 253] Meeting Rooms II
- [LC 2402] Meeting Rooms III
    - O(m * log m + m * log n)


# Lessons
- Maintain sliding window for if subarray with something < k, or > k, [LC 1004]
- Maintain aggregations at indexes for range updates [LC 3355/3356/995]
- To take few from start and few from back, append at back and do sliding window [LC 1423]
- Count subarrays by sliding window [LC 1918]
- Maintain pq, deque, trees for finding stuff from index < n, [LC 1918]

