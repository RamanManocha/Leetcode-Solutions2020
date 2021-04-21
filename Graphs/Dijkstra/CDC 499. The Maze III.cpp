

499. The Maze III
Hard

243

47

Add to List

Share
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. There is also a hole in this maze. The ball will drop into the hole if it rolls onto the hole.

Given the m x n maze, the ball's position ball and the hole's position hole, where ball = [ballrow, ballcol] and hole = [holerow, holecol], return a string instructions of all the instructions that the ball should follow to drop in the hole with the shortest distance possible. If there are multiple valid instructions, return the lexicographically minimum one. If the ball can't drop in the hole, return "impossible".

If there is a way for the ball to drop in the hole, the answer instructions should contain the characters 'u' (i.e., up), 'd' (i.e., down), 'l' (i.e., left), and 'r' (i.e., right).

The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).

You may assume that the borders of the maze are all walls (see examples).

 

Example 1:


Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], ball = [4,3], hole = [0,1]
Output: "lul"
Explanation: There are two shortest ways for the ball to drop into the hole.
The first way is left -> up -> left, represented by "lul".
The second way is up -> left, represented by 'ul'.
Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'. So the output is "lul".
Example 2:


Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], ball = [4,3], hole = [3,0]
Output: "impossible"
Explanation: The ball cannot reach the hole.
Example 3:

Input: maze = [[0,0,0,0,0,0,0],[0,0,1,0,0,1,0],[0,0,0,0,1,0,0],[0,0,0,0,0,0,1]], ball = [0,4], hole = [3,5]
Output: "dldr"
 

Constraints:

m == maze.length
n == maze[i].length
1 <= m, n <= 100
maze[i][j] is 0 or 1.
ball.length == 2
hole.length == 2
0 <= ballrow, holerow <= m
0 <= ballcol, holecol <= n
Both the ball and the hole exist in an empty space, and they will not be in the same position initially.
The maze contains at least 2 empty spaces.





class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{1,0},{0,-1},{0,1},{-1,0}};
    bool isCorner(int x, int y, int d, vector<vector<int>>& maze)
    {
        int newX = x + dirs[d][0];
        int newY = y + dirs[d][1];
        if (newX < 0 || newX >=m || newY < 0 || newY >= n || maze[newX][newY] == 1)
            return true;
        return false;
    }
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        if (ball[0] == hole[0] && ball[1] == hole[1])
            return "";
        m = maze.size(), n = maze[0].size();
        queue<pair<int, string>> q;
        vector<vector<int>> visited(m, vector<int>(n,0));
        string dirStr = "dlru";
        int x, y, newX, newY, d;
        string currStr;
        for(d=0;d<4;d++)
        {
            if (!isCorner(ball[0], ball[1], d, maze))
            {
                q.push({ball[0]*n + ball[1], string(1, dirStr[d])});
                visited[ball[0]][ball[1]] |= (1<<d);
            }
        }
        
        while (!q.empty())
        {
            x = q.front().first/n;
            y = q.front().first%n;
            currStr = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
                if (dirStr[i] == currStr.back())
                {
                    d = i;
                    break;
                }

            newX = x + dirs[d][0];
            newY = y + dirs[d][1];
            
            if (newX == hole[0] && newY == hole[1])
                return currStr;
            else if (!isCorner(newX, newY, d, maze))
            {
                if ((visited[newX][newY] & (1<<d)) == 0)
                {
                    q.push({newX*n+newY, currStr});
                    visited[newX][newY] |= (1<<d);
                }
            }
            else
            {
                for(int i=0;i<4;i++)
                {
                    if (i != d && (visited[newX][newY] & (1<<i)) == 0 &&
                       !isCorner(newX, newY, i, maze))
                    {
                        visited[newX][newY] |= (1<<i);
                        q.push({newX*n + newY, currStr + string(1, dirStr[i])});
                    }
                }
            }
        }
        
        return "impossible";
    }
};
