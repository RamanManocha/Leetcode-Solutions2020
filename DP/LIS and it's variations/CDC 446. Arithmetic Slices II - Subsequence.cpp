


446. Arithmetic Slices II - Subsequence
Hard

701

69

Add to List

Share
Given an integer array nums, return the number of all the arithmetic subsequences of nums.

A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
A subsequence of an array is a sequence that can be formed by removing some elements (possibly none) of the array.

For example, [2,5,10] is a subsequence of [1,2,1,2,4,1,5,10].
The answer is guaranteed to fit in 32-bit integer.

 

Example 1:

Input: nums = [2,4,6,8,10]
Output: 7
Explanation: All arithmetic subsequence slices are:
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
Example 2:

Input: nums = [7,7,7,7,7]
Output: 16
Explanation: Any subsequence of this array is arithmetic.
 

Constraints:

1  <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1







class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A, int res = 0) {
    unordered_map<int, int> m[max(1, (int)A.size())];
    unordered_set<int> s(begin(A), end(A));
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < i; ++j) {
            long d = (long)A[i] - A[j];
            if (d < INT_MIN || d > INT_MAX)
                continue;
            auto it = m[j].find(d);
            int cnt = it == end(m[j]) ? 0 : it->second;
            if (s.count((long)A[i] + d))
                m[i][d] += cnt + 1;
            res += cnt;
        }
    return res;
}
};


// dp[i][d] -> denotes numer of subsequences end at ith index having common difference as d.
// Since common difference can be negative that's why using map is appropriate.

// If we are at ith index then we check for all j that are less than i , having a common diffrence of ( a[i] - a[j] ) , and number of sequences ending at jth index having common difference as ( a[i] - a[j] ) to sequence dp[i][ ( a[i] - a[j] ) ] and since we need to make sure that every sequence should be of len >= 3 , so for diffrence ( a[i] - a[j] ) , we will add 1 to dp[i][ ( a[i] - a[j] ) ] and now at ith index we have 2 len sequence ending at ith which becomes jth for all indices greater than ith.

    
    
// class Solution
// {
// public:
// int numberOfArithmeticSlices(vector& a)
// {

// 	int n  = a.size();
//     map<long long int, long long int > dp[n+1];
//     long long int ans = 0;
    
//     for( int i = 0; i < n; i++)
//     {
//         for( int j = 0; j < i; j++)
//         {
//             long long int d = 1LL*a[i] - 1LL*a[j];
            
//             if( dp[j].count( d ) ) 
//             {
//                 ans += dp[j][d];
//                 dp[i][d] += dp[j][d];
//             }
            
//             dp[i][d] += 1;
//         }
//     }
    
//     return ans;
            
// }
// };
