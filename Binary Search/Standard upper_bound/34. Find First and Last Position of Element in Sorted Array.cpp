


34. Find First and Last Position of Element in Sorted Array
Medium

5460

209

Add to List

Share
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109





class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int idx1 = lower_bound(nums, target);
    int idx2 = lower_bound(nums, target+1)-1;
    if (idx1 <= idx2) return {idx1, idx2};
    else return {-1, -1};
    
}

int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size()-1;
    while (l <= r) {
        int mid = (r-l)/2+l;
        if (nums[mid] < target)
            l = mid+1;
        else
            r = mid-1;
    }
    return l;
}
};
