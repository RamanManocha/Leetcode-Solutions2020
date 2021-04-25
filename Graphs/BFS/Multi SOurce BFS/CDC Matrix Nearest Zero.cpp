

Matrix Nearest Zero
You are given a two-dimensional list of integers matrix containing 1s and 0s. Return the same matrix except each cell's value is now the Manhattan distance to the nearest 0. You can assume at least one 0 exists in the matrix.

Constraints

0 ≤ n, m ≤ 250 where n and m are the number of rows and columns for matrix.
Example 1
Input
matrix = [
    [1, 1, 1],
    [1, 0, 1],
    [0, 0, 0]
]
Output
[
    [2, 1, 2],
    [1, 0, 1],
    [0, 0, 0]
]
Explanation
Only the top left and top right squares have distance of 2 to the nearest 0.






vector<vector<int>> solve(vector<vector<int>>& arr) {
    int n = arr.size(), m = arr[0].size();
    // directions
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // mark all one's as INF
            if (arr[i][j]) {
                arr[i][j] = 1e9;
            }
            // collect all source node(you call this multi-source BFS)
            else
                q.push({i, j});
        }
    }
    // perfrom dijkstra algorithm
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if ((xx < n && xx >= 0 && yy < m && yy >= 0) and arr[xx][yy] > arr[x][y] + 1) {
                arr[xx][yy] = arr[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
    // hurray ! we made it to the end.
    return arr;
}
