# Stacks and Queues Notes

## Questions

- [LC 394] Decode String
- [LC 32] Longest Valid Parentheses
    - InterviewBit [link](https://www.interviewbit.com/problems/longest-valid-parentheses/)
- [LC 3282] Reach End of Array With Max Score
    - Monotonic Stack
    - Or start from back and just maintain maxSoFar
- [LC 581] Shortest Unsorted Continuous Subarray
    - Solution 1 => sort the array and compare, TC => (n)log(n)
    - Solution 2 => monotonic stack from both sides, TC => n
- [LC 2534] Time Taken to Cross the Door
    - Simulate the complete flow in brute force, it is O(n)
- Interview Question
    - [Link](https://leetcode.com/discuss/post/6696099/google-l3-onsite-r3-by-anonymous_user-8nma/)
- [LC 1944] Number of Visible People in a Queue
    - Monotonic stack
- [LC 768] Max Chunks To Make Sorted II
    - Monotonic Stack
    - Maintain stack of max element of each chunk
- [LC 402] Remove K Digits
    - Monotonic Stack
    - [Link](https://leetcode.com/problems/remove-k-digits/description/)
    - [Similar/inspired](https://leetcode.com/discuss/post/5293722/phone-screen-by-anonymous_user-zl2c/)

- [LC 218] The Skyline Problem
    - Aggregate points of ranges, heights to be added & heights to be removed
    - But do not use prioity queue, use Self Balancing Binary Search Tree, AVL tree
    - Final TC => nlog(n)

- [LC 1851] Minimum Interval to Include Each Query
    - Sort both intervals and queries
    - Iterate over queries and maintain a pq
        - Keep adding in pq while interval is valid
        - Keep removing from pq while top interval is in valid
        - Record min window for current query
