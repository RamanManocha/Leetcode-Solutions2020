







79. Word Search
Medium

5618

245

Add to List

Share
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?













// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
        
//     }
// };


class Solution {
    bool search(vector<vector<char>>& board, int i, int j, string& word, int idx){
        if(idx == word.length() - 1) return true;
        board[i][j] -= 'A';
        if(i > 0 && board[i-1][j] == word[idx+1] && search(board, i-1, j, word, idx+1)) return true;
        if(j > 0 && board[i][j-1] == word[idx+1] && search(board, i, j-1, word, idx+1)) return true;
        if(i < board.size()-1 && board[i+1][j] == word[idx+1] && search(board, i+1, j, word, idx+1)) return true;
        if(j < board[0].size()-1 && board[i][j+1] == word[idx+1] && search(board, i, j+1, word, idx+1)) return true;
        board[i][j] += 'A';
        return false;
}

public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        if(r == 0) return false;
        int c = board[0].size();
        for(int i = 0; i < r; ++i)
            for(int j = 0; j < c; ++j)
                if(board[i][j] == word[0] && search(board, i, j, word, 0)) return true;
        return false;
    }
};




  class Solution {
  	public:
  		bool search(vector<vector<char>>& board, int i, int j, string& word, int idx, vector<vector<bool>>& visited){
  			// if it is the last char of word, Signifies that we have reached the end of word
  			if(idx == word.length()-1)
  				return true;
  			// else mark visited and call DFS for neighbour in 4 direction
  			visited[i][j] = true;
  			// call DFS for neighbour in 4 direction and increase the index
  			if(i > 0 && !visited[i-1][j] && board[i-1][j] == word[idx+1] && search(board, i-1,j,word,idx+1,visited))
  				return true;

  			if(j > 0 && !visited[i][j-1] && board[i][j-1] == word[idx+1] && search(board, i,j-1,word,idx+1,visited))
  				return true;

  			if(i < board.size()-1 && !visited[i+1][j] && board[i+1][j] == word[idx+1] && search(board, i+1,j,word,idx+1,visited))
  				return true;

  			if(j < board[0].size()-1 && !visited[i][j+1] && board[i][j+1] == word[idx+1] && search(board, i,j+1,word,idx+1,visited))
  				return true;
  			// if backtrack mark it as false
  			visited[i][j] = false;
  			// if none of the case satisfy then return it as false;
  			return false;
  	}

  	bool exist(vector<vector<char>>& board, string word) {
  		int n = board.size();
  		int m = board[0].size();

  		//initilizing visited with false
  		vector<vector<bool>> visited(n, vector<bool>(m,false));

  		for(int i = 0; i < n; i++)
  		{
  			for(int j = 0; j < m; j++)
  			{   //if 0th char  matches then search for rest of char against that index in dfs search
  				if(board[i][j] == word[0] && search(board, i,j,word,0,visited))
  					return true;
  			}
  		}
  		return false;
  	 }
  	};





