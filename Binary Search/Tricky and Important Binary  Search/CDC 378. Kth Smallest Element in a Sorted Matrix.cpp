378. Kth Smallest Element in a Sorted Matrix


https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/







378. Kth Smallest Element in a Sorted Matrix
Medium

3585

183

Add to List

Share
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length
n == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2





class Solution {
private:
    int countSmaller(vector<vector<int>>& a, int k){
        int n = a.size();
        int count = 0;
        int i = 0, j = n - 1;
        while(i < n && j >= 0){
            if(a[i][j] > k) j --;
            else{
                count += j + 1;  // +1 because it's zero based indexing
                i++;
            }
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        if(a.size() == 0) return -1;
        int result = -1;
        int low = a[0][0], high = a[a.size()-1][a.size()-1];
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            if(countSmaller(a, mid) >= k){
                result = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return result;
    }
};
