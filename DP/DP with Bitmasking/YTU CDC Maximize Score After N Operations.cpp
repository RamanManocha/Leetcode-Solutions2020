
https://leetcode.com/problems/maximize-score-after-n-operations/


1799. Maximize Score After N Operations
Hard

65

3

Add to List

Share
You are given nums, an array of positive integers of size 2 * n. You must perform n operations on this array.

In the ith operation (1-indexed), you will:

Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
Return the maximum score you can receive after performing n operations.

The function gcd(x, y) is the greatest common divisor of x and y.

 

Example 1:

Input: nums = [1,2]
Output: 1
Explanation: The optimal choice of operations is:
(1 * gcd(1, 2)) = 1
Example 2:

Input: nums = [3,4,6,8]
Output: 11
Explanation: The optimal choice of operations is:
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
Example 3:

Input: nums = [1,2,3,4,5,6]
Output: 14
Explanation: The optimal choice of operations is:
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 

Constraints:

1 <= n <= 7
nums.length == 2 * n
1 <= nums[i] <= 106







class Solution {
public:
    vector<vector<int> > m;
    vector<unordered_map<int, int> > dp;
    int gcd(int a, int b) {
        if (a % b == 0) return b;
        return gcd(b, a % b);
    }
    int dfs(vector<int>& nums, int mask, int step) {
        if(mask + 1 == (1 << nums.size() )) return 0;
        if(dp[step].count(mask)) return dp[step][mask];
        int res = 0;
        for(int i = 0; i < m.size(); ++i) {
            int a = m[i][0];
            int b = m[i][1];
            if((mask & (1<< a)) || (mask & (1 << b))) continue;
            res = max(res, step * m[i][2] + dfs(nums, mask | (1 << a) | (1 << b), step + 1));
            
        }
        return dp[step][mask] = res;
    }
    int maxScore(vector<int>& nums) {
        dp.resize(nums.size());
        int ms = 1 << nums.size();
        for(int i = 3; i < ms; ++i) {
            int a = -1, b = -1;
            int cnt = 0;
            for(int j = 0; j < nums.size(); ++j) {
                if((1 << j) & i) {
                    if(a == -1) a = j;
                    else if(b == -1) b = j;
                    ++cnt;
                }
            }
            if(a >= 0 && b >= 0 && cnt == 2) {
                m.push_back({a, b, gcd(nums[a], nums[b])});
            }
        }
        return dfs(nums, 0, 1);
    }
};
