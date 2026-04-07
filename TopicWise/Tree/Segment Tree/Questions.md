# Segment Tree Questions

## Lesson
- [LC 2250]

## Questions
- [LC 2407] Longest Increasing Subsequence II
    - Good question
- [LC 715] Range Module
    - Can be done by maintaining a sorted set of disjoint intervals, but TC => O(n) even with binary search
    - Segment tree does it in log(n)
- [LC 2250] Count Number of Rectangles Containing Each Point
    - Tweaked question with no limits [link](https://leetcode.com/discuss/post/4979440/google-online-assessment-by-anonymous_us-u3is/)
    - Sort servers and queries
    - Start from large x, keep adding y in segment tree
    - TC => NlogN + QlogQ + (N+Q)*log(N)

- Interview Question
    - [Round 3](https://leetcode.com/discuss/post/5966234/google-bangalore-experience-l4-by-anonym-yf6f/)
    - 2D segment tree
    - Works becuase GCD is associative

- [LC 850] Rectangle Area II
    - Brute force
        - Get all unique (x, y), sort them and consider them as small cells => n^2 cells
        - For each cell check if it is in any rectangle => n checks
        - TC => n^3
    - Optimized
        - Sweep x cordinates, at each x coordinate, add/remove y range in segment tree
        - TC => nlog(n) + nlog(m), m is y coordinates, segment tree will have m elements
