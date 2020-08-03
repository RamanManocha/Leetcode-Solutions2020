489. Robot Room Cleaner
Hard

1014

59

Add to List

Share
Given a robot cleaner in a room modeled as a grid.

Each cell in the grid can be empty or blocked.

The robot cleaner with 4 given APIs can move forward, turn left or turn right. Each turn it made is 90 degrees.

When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays on the current cell.

Design an algorithm to clean the entire room using only the 4 given APIs shown below.

interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}
Example:

Input:
room = [
  [1,1,1,1,1,0,1,1],
  [1,1,1,1,1,0,1,1],
  [1,0,1,1,1,1,1,1],
  [0,0,0,1,0,0,0,0],
  [1,1,1,1,1,1,1,1]
],
row = 1,
col = 3

Explanation:
All grids in the room are marked by either 0 or 1.
0 means the cell is blocked, while 1 means the cell is accessible.
The robot initially starts at the position of row=1, col=3.
From the top left corner, its position is one row below and three columns right.
Notes:

The input is only given to initialize the room and the robot's position internally. You must solve this problem "blindfolded". In other words, you must control the robot using only the mentioned 4 APIs, without knowing the room layout and the initial robot's position.
The robot's initial position will always be in an accessible cell.
The initial direction of the robot will be facing up.
All accessible cells are connected, which means the all cells marked as 1 will be accessible by the robot.
Assume all four edges of the grid are all surrounded by wall.




We want to do a DFS with backtracking.
The following details are different in this problem than a common dfs problem:
1.A way to encode already visited positions (The easy solution is just use relative positions from the starting point)
2.A way to backtrack (The concept is the same, we want to reset the position to what it originally was. In this case the direction is also added in, so we want to reset the direction it's facing to the direction it originally was facing with the original position).

I assume the robot is starting facing upwards, but any direction works as long as the order of the directions match the direction with the turning.

The algorithm starts off at 0,0 which is our starting point (the boards starting point doesn't matter, and it doesn't matter that there are negative positions), as long as all the values are consistent. We add this position to our visited list and clean it. For each of the 4 directions, we calculate its next row and next column (remember that we are currently facing in the last direction moved, in this code's case the variable curDirection) if we went in that direction. If the next position is unvisited we try moving there. If we are able to move we call it recursively down the next branch.

After we return from the recursive call we need to backtrack:

                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnRight();
                robot.turnRight();
or we can use 2 robot.turnLeft()s like I did.
We reset the state by turning 180 degrees, moving, and then changing the direction back to what it originally was by turning another 180 degrees.
Then we try the next direction (turning it to the right). After all 4 directions are tried it is automatically turned to the original direction after the loop since we turned right 4 times.

class Solution {
public:
    unordered_map<int, unordered_map<int, int>> data;
    int x=0;
    int y=0;
    int dx[4]={1, 0, -1, 0};
    int dy[4]={0, 1, 0, -1};
    int dir=0;
    void cleanRoom(Robot& robot) {
        if(data[x][y]==1){
            return;
        }
        data[x][y]=1;
        robot.clean();
        for(int i=0; i<4; i++){
            if(robot.move()){
                x+=dx[dir];
                y+=dy[dir];
                cleanRoom(robot);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
                x-=dx[dir];
                y-=dy[dir];
            }
            robot.turnRight();
            dir=(dir+1)%4;
        }
    }
};
