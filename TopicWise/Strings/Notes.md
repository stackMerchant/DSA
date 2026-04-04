# Strings Notes

## KMP
- lps[i] = longest prefix == suffix for s[0...i]
- Use in streams where we can't do full text concat and serach for Z

## Z algo
- Z(i) => longest sub-string starting from i which is also a prefix of string

```cpp
vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    int L = 0, R = 0;

    for (int i=1; i<n; i++) {
        if (i <= R) z[i] = min(z[i-L], R-i+1); // update from previous match window

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++; // extend beyond window
        
        // if current match is going beyond last match window, update window
        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
    return z;
}
```

## Questions

- [LC 3303] Find the Occurrence of First Almost Equal Substring
    - Good question
    - prefix and suffix, around the character to change
    - Z algo
    - Let L[i] = number of matching chars from the start
    - Let R[i] = number of matching chars from the end
    - For any i => if L[i] + R[i + m - 1] >= m - 1 => valid match
    - Note: not just equal to m or m-1, because of overlaps

- Interview question, good one
    - [Link](https://leetcode.com/discuss/post/6927378/google-phone-screen-reject-by-anonymous_-muov/)
    - Use trie to hash rows
    - Do brute force match, improve by Z or KMP
