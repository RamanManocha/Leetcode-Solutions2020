


1198. Find Smallest Common Element in All Rows
Medium

259

16

Add to List

Share
Given an m x n matrix mat where every row is sorted in strictly increasing order, return the smallest common element in all rows.

If there is no common element, return -1.

 

Example 1:

Input: mat = [[1,2,3,4,5],[2,4,5,8,10],[3,5,7,9,11],[1,3,5,7,9]]
Output: 5
Example 2:

Input: mat = [[1,2,3],[2,3,4],[2,3,5]]
Output: 2
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 104
mat[i] is sorted in strictly increasing order.





Algorithm:

Iterate through the first row in O(C) time.
Check if current element is common -- search for it in every other row in O(RlogC) time.
First common element is an answer, because rows are sorted.
Total complexity: O(RClogC)

int smallestCommonElement(vector<vector<int>>& mat) {
        // corner case
        if (mat.size() == 1)
            return mat[0][0];
			
        for (int v : mat[0]) {
            bool is_common = true;
            for (auto &row : mat) {
                // Note: first row wasn't skipped for simplicity 
                if (!binary_search(begin(row), end(row), v)) {
                    is_common = false;
                    break;
                }                    
            }
            if (is_common)
                return v;
        }
        return -1;
    }
    
    
    
