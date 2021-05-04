


Sort List by Reversing Once
You are given a list of integers nums. Given that you can first reverse one sublist in nums, return whether you can make the resulting list be arranged in ascending order.

Constraints

0 ≤ n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 3, 3, 7, 6, 9]
Output
true
Explanation
If we reverse the sublist [7, 6], then we can sort the list in ascending order: [1, 3, 3, 6, 7, 9].

Example 2
Input
nums = [1, 3, 9, 8, 2]
Output
false
Explanation
There's no way to reverse any sublist to sort nums in ascending order.

Example 3
Input
nums = [1, 2, 3, 4]
Output
true
Explanation
This list is already sorted in ascending order so we can reverse any sublist of length 1. For example, reverse [2] to get the same [1, 2, 3, 4].





bool solve(vector<int>& nums) {
    vector<int> v;
    v = nums;
    sort(v.begin(), v.end());
    int l = -1, r = -1;
    for (int i = 0; i < nums.size(); i += 1) {
        if (v[i] != nums[i]) {
            if (l == -1) l = i;
            r = i;
        }
    }
    if (l == -1) return true;
    while (l < r) {
        swap(nums[l], nums[r]);
        l += 1, r -= 1;
    }
    return nums == v;
}
