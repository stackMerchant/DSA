# Segment Tree Questions

- [LC 2407]
- [LC 850] Rectangle Area II // not done

- [LC 2250] Count Number of Rectangles Containing Each Point
    - Tweaked question with no limits [link](https://leetcode.com/discuss/post/4979440/google-online-assessment-by-anonymous_us-u3is/)
    - Sort servers and queries
    - Start from large x, keep adding y in segment tree
    - TC => NlogN + QlogQ + (N+Q)*log(N)
