




Pair Matches Larger Than Target
You are given a list of integers nums and an integer target. Return the maximum number of pairs where for each pair i < j, i and j are not in any other pair, and 
abs(nums[i] - nums[j]) ≥ target.

Constraints

n ≤ 100,000 where n is the length of nums
Example 1
Input
nums = [1, 3, 5, 9, 10]
target = 3
Output
2
Explanation
We can have the following pairs: (1, 5), (3, 9)






int solve(vector<int>& nums, int target) {
    multiset<int> sett;
    sort(nums.begin(), nums.end());
    for (int i = nums.size() / 2; i < nums.size(); i++) {
        sett.insert(nums[i]);
    }

    int ans = 0;
    for (int i = 0; i < nums.size() / 2; i++) {
        auto it = sett.lower_bound(nums[i] + target);

        if (it != sett.end()) {
            ans++;
            sett.erase(it);
        } else
            break;
    }

    return ans;
}
