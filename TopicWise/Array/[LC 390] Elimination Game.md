# [LC 390] Elimination Game

```cpp
class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        bool fromLeft = true;
        while (n > 1) {
            if (fromLeft || n%2 == 1) {
                head += step;
            }

            step *= 2;
            n /= 2;
            fromLeft = !fromLeft;
        }
        return head;
    }
};
```
