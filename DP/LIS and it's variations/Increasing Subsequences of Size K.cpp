Increasing Subsequences of Size K
Given a list of integers nums and an integer k, return the number of subsequences of size k that are strictly increasing.

Mod the result by 10 ** 9 + 7.

Constraints

n ≤ 1,000 where n is the length of nums.
k ≤ 10
Example 1
Input
nums = [1, 2, 3, 0]
k = 2
Output
3
Explanation
We have the following increasing subsequences of size 2: [1, 2], [2, 3], [1, 3]




int solve(vector<int>& nums, int k) {
    int n = (int)nums.size(), dp[k][n], ans = 0, mod = 1e9 + 7;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) dp[0][i] = 1;
    for (int l = 1; l < k; l++) {
        for (int i = l; i < n; i++) {
            dp[l][i] = 0;
            for (int j = l - 1; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[l][i] = (dp[l][i] + dp[l - 1][j]) % mod;
                }
            }
        }
    }
    for (int i = k - 1; i < n; i++) {
        ans = (ans + dp[k - 1][i]) % mod;
    }
    return ans;
}
