Longest Sublist with K Distinct Numbers
Given an integer k and a list of integers nums, return the length of the longest sublist that contains at most k distinct integers.

Constraints

0 ≤ k ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
k = 2
nums = [0, 1, 2, 1, 0]
Output
3
Explanation
The longest substring with 2 distinct integers is [1,2,1], which has length of 3.

Example 2
Input
k = 1
nums = [0, 0, 0, 0, 0]
Output
5
Example 3
Input
k = 1
nums = [0, 1, 2, 3, 4]






int solve(int k, vector<int>& nums) {
    unordered_map<int, int> ct;
    int j = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
        ++ct[nums[i]];
        while (ct.size() > k) {
            --ct[nums[j]];
            if (ct[nums[j]] == 0) {
                ct.erase(nums[j]);
            }
            ++j;
        }
        ans = max(ans, i - j + 1);
    }
    return ans;
}
