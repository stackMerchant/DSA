# Questions

## Done
- [LC 359] Logger Rate Limiter
    - Use a queue + map, if do not want memory to blow up
    - If that is fine, use just a map with TTL

- [LC 1825] Finding MK Average

- Interview Question *
    - [Link](https://leetcode.com/discuss/post/6886191/need-on-solution-for-the-below-question-5k7t7/)
    - Brute Force => n^2, optimal => n
    - Idea is to remove element one by one, then calculate prefix sum and suffix sum, and see if it is equal, n^2
    - Optimization => Create prefix sum and suffix sum, at each junction check if difference is present before using a map
    - Do it both ways


