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

