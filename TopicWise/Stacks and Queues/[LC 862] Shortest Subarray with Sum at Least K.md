# [LC 862] Shortest Subarray with Sum at Least K

- [Link](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/)
- [Solution explanation](https://www.youtube.com/watch?v=5AY70aAHZiQ)

- Brute force is n^2
- Better approach with pq
    - Calculate running prefix and put it in pq
    - Use pq to find minimum prefix that we can subtract to get sum >= k
    - Pop after processing
- Best approach with monotonic stack
    - Use a monotonic increasing Deque
    - Check from back and remove for processed sums
    - Check from front and remove bigger prefixes


```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans = -1, n = nums.size();
        long long prefixSum = 0;

        deque<pair<long long, int>> dq;
        dq.push_back({0, -1});
        for (int i=0; i<n; i++) {
            prefixSum += nums[i];

            while (!dq.empty() && prefixSum - dq.front().first >= k) {
                if (ans == -1) ans = i - dq.front().second;
                else ans = min(ans, i - dq.front().second);
                
                dq.pop_front();
            }

            while (!dq.empty() && dq.back().first >= prefixSum) {
                dq.pop_back();
            }
            dq.push_back({prefixSum, i});
        }
        return ans;
    }
};
```

