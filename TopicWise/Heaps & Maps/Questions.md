# Questions

## Done
- [LC 359] Logger Rate Limiter
    - Use a queue + map, if do not want memory to blow up
    - If that is fine, use just a map with TTL

- LC 1825
- [LC 632] Smallest Range Covering Elements from K Lists

- Interview Question
    - [Link](https://leetcode.com/discuss/post/6886191/need-on-solution-for-the-below-question-5k7t7/)
    - Brute Force => n^2, optimal => n
    - Create prefix sum and suffix sum, check for difference in higher part by map
