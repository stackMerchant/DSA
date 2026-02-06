# Backtracking Notes

## Generate all paranthesis

Generationg of combinations is exponential time
And counts are catalan number, C(n) = Sigma [i = (0 -> n-1)] (C(i) * C(n-i-1))
And calculating this through DP is O(n^2) as 1 + 2 + 3 + .... + n-1

#### Catalan numbers

Also used in BST combinations
