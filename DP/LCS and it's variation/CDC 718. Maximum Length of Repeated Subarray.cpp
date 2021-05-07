



718. Maximum Length of Repeated Subarray
Medium

2030

55

Add to List

Share
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100










class Solution {
public:
   int findLength( vector<int>& A, vector<int>& B ) {
	int m = A.size(), n = B.size();

	//dp[i][j] is the length of longest common subarray ending with A[i] and B[j]
	vector<vector<int>> dp( m+1, vector<int>(n+1, 0) );
	int result = 0;
	for( int i=1; i<=m; i++ ) {
		for( int j=1; j<=n; j++ ) {
			if( A[i-1] == B[j-1] ) {
				dp[i][j] = dp[i-1][j-1] + 1;
				result = max( result, dp[i][j] );
			} else
				dp[i][j] = 0;
		}
	}
	return result;
}
};
