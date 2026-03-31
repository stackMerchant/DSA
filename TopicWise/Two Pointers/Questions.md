# Two Pointers Questions

- [LC 11] Container With Most Water
    - TC => O(n)
- Rain water trapping in O(1) space
    - [LC 42] Trapping Rain Water
- [LC 647] Palindromic Substrings

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
