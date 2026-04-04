# Array Notes

## Sieve of Eratosthenes
- TC = n(log(log(n))), base doesn't matter in O(), but it is natural log
- [Question](https://leetcode.com/discuss/post/6607054/l4-onsite-question-by-anonymous_user-uqma/)
    - Get prime factors, using sieve
    - Then just need to partition in a way that a prime on left side is not on right side
    - Expand the boundary until all primes you've seen so far are fully contained
    - Can also use a multiplication division type algo


## Sorting
- [LC 759] Employee Free Time
- [LC 435] Non-overlapping Intervals
    - Sort by end time, and just not count overlapping intervals, voila


# Array Questions

- [[LC 3394] Check if Grid can be Cut into Sections](https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/)
- [LC 2018] Check if Word Can Be Placed In Crossword
    - TC => O(nmk)
- [LC 2575] Find the Divisibility Array of a String
    - Running remainder


# Count number freq
- Formula => frequency=(i+1)×(n−i)
- Array => 12345
```
1 2 3 4 5
12 23 34 45
123 234 345
1234 2345
12345
```


# See solution
- Knapsack with only 1/2
- K smallest on left, SEE
