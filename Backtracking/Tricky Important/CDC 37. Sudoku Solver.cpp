


https://leetcode.com/problems/sudoku-solver/




37. Sudoku Solver
Hard

2718

104

Add to List

Share
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution






class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        
        // dp[left][right] = the min move for arr[left]...arr[right] (both included).
        // the max number of move is n.
        vector<vector<int>> dp(n, vector<int>(n, n));
        
        // handle edge situation: subarray size == 1
        for(int i = 0; i < n; i++) { dp[i][i] = 1; }
        
        // handle edge situation: subarray size == 2
        for(int i = 0; i < n - 1; i++) { dp[i][i + 1] = arr[i] == arr[i + 1] ? 1 : 2; }
        
        // for subarray size >= 3:
        for(int size = 3; size <= n; size++) {
            for(int left = 0, right = left + size - 1; right < n; left++, right++) {
                
                // if arr[left] == arr[right], then the two number: arr[left] and arr[right] can be
                // removed when the last move of subarray arr[left + 1:right - 1]
                if(arr[left] == arr[right]) {
                    dp[left][right] = dp[left + 1][right - 1];
                }
                
                // or, if we cannot remove arr[left] and arr[right] in one move (the last move),
                // the subarray arr[left:right] must can be split into two subarrays
                // and remove them one by one.
                for(int mid = left; mid < right; mid++) {
                    dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid + 1][right]);
                }
            }
        }
        return dp[0][n - 1];
    }
};


