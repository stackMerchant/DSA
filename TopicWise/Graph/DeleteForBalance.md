# Balance paranthesis

- [Link](https://leetcode.com/discuss/post/5121570/google-phone-screen-balance-paranthesis-6q2eq/)
- TC => O(n * possible_balances * d)

```cpp
#include <iostream>
#include <set>
#include <string>

bool canBalance(const std::string& s) {
    std::set<int> states = {0};   // possible balances, balance = number_of_open - number_of_close
    int surviving = 0;            // number of parentheses remaining so far

    for (char ch : s) {
        std::set<int> next;

        if (ch == '(') {
            for (int b : states) {
                next.insert(b + 1);
            }
            surviving++;
        }

        else if (ch == ')') {
            for (int b : states) {
                if (b > 0) {
                    next.insert(b - 1);
                }
            }
            surviving++;
        }

        else {  // digit
            int d = ch - '0';

            if (surviving < d)
                return false;

            for (int b : states) {
                /*
                    open - close = balance
                    open + close = surviving
                */
                int numOpen  = (surviving + b) / 2;
                int numClose = (surviving - b) / 2;

                for (int k = 0; k <= d; k++) {
                    // k = number of '(' deleted
                    // d-k = number of ')' deleted
                    if (k <= numOpen && (d - k) <= numClose) {
                        // open'  = numOpen - k
                        // close' = numClose - (d - k)
                        // newBalance = open' - close'
                        int newBalance = b + d - 2 * k;
                        if (newBalance >= 0) {
                            next.insert(newBalance);
                        }
                    }
                }
            }

            surviving -= d;
        }

        states = next;

        if (states.empty())
            return false;
    }

    return states.count(0) > 0;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << canBalance("((2))") << std::endl;   // false
    std::cout << canBalance("((((2))") << std::endl; // true
    std::cout << canBalance("(()1(1))") << std::endl; // true
}
```
