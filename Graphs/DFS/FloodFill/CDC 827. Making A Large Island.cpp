


https://leetcode.com/problems/making-a-large-island/discuss/1057453/DFS-C%2B%2B-intuitive-solution-with-explanation-O(n*n)



827. Making A Large Island
Hard

762

23

Add to List

Share
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.








class Solution {
public:
    int isColoured(vector<vector<int>>& grid, int i, int j){
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]!=0 && grid[i][j]!=1)
            return grid[i][j];
        return -1;
    }
    vector<int> getColours(vector<vector<int>>& grid, int i, int j){
        set<int> v;
        
        if(isColoured(grid, i+1,j)!=-1) v.insert(isColoured(grid, i+1,j));
        if(isColoured(grid, i-1,j)!=-1) v.insert(isColoured(grid, i-1,j));
        if(isColoured(grid, i,j+1)!=-1) v.insert(isColoured(grid, i,j+1));
        if(isColoured(grid, i,j-1)!=-1) v.insert(isColoured(grid, i,j-1));
        
        vector<int> ret(v.begin(),v.end());
        
        return ret;
    }
    void Colour(vector<vector<int>>& grid, int i, int j, int color, int& sz){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1)
            return;
        grid[i][j]=color;
        sz++;
         Colour(grid, i+1,j,color,sz);
         Colour(grid, i-1,j,color,sz);
         Colour(grid, i,j-1,color,sz);
         Colour(grid, i,j+1,color,sz);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int M=0;
        unordered_map<int,int> getsize;
        int color = 2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                int sz = 0;
                if(grid[i][j]==1){
                    Colour(grid,i,j,color,sz);
                    getsize[color]=sz;
                    M=max(M, sz+1);
                    color++;
                }
            }
        }
      
   
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                   vector<int> coloredNeighbours = getColours(grid, i, j);
                 
                    
                    int sum = 0;
                        for(auto x:coloredNeighbours){
                            sum+=getsize[x];
                        }
                    M=max(M, sum+1);
                }
            }
        }
        return min(M, (int)(grid.size()*grid[0].size()));
    }
};
