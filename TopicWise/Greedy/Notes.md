# Greedy notes

## Lessons
- Bricks and ladders, take all first, then later drop worst

## Huffman Coding
- [Huffman 1](https://www.youtube.com/watch?v=uDS8AkTAcIU)
- [Huffman 2](https://www.youtube.com/watch?v=ocFO1rmh4Zc)
- It does not need a separator, as it is prefix free
- There is no ambiguity on decoding as codes end on leafs, so a code can't pe prefix of another code

# Questions
- [LC 767] Reorganize String
    - Count occurences and place alternately evens and then odds
- [LC 846] Hand of Straights & [LC 1296] Divide Array in Sets of K Consecutive Numbers
    - Sort and then fill groups, OR
    - Do not sort and start anywhere and then keep going back to find a start and then fill

- [LC 1642] Furthest Building You Can Reach
    - Ladders and bricks
- [LC 630] Course Schedule III
    - push current in pq and check if deadline is breached, keep popping till deadline is back

- Interview question
    - [Link](https://leetcode.com/discuss/post/6789894/l4-google-question-by-anonymous_user-pork/)
    - Count balls of each color, pack them in same color bags, ni/k bags
    - ni % k balls left of each color
    - max(rem[i]) bags more required

## More questions
- [Conclude greedy](https://leetcode.com/discuss/post/1402757/conclude-greedy-with-baba-by-baba_rude-83as/)
