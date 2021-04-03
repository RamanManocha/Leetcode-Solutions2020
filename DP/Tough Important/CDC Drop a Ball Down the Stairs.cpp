
Drop a Ball Down the Stairs


You are given an integer height and a list of integers blacklist. You are currently standing at height height and you are playing a game to move a 
small ball down to height 0.

In even rounds (0, 2, 4, 6 etc.) you can move the ball down 1, 2, or 4 stairs down. In odd rounds, you can move the ball down 1, 3, or 4 stairs. There 
are some levels of the stairs where if the ball lands there, it will die as labelled in blacklist. Return number of ways you can move the ball down to 
height 0. Mod the result by 10 ** 9 + 7.

Constraints

1 ≤ height ≤ 100,000
0 ≤ b ≤ 100,000 where b is the length of blacklist
Example 1
Input
height = 4
blacklist = [2]
Output
2
Explanation
We can move 4 stairs down on round 0.
We can move 1 stair down on round 0 and then 3 stairs down on round 1.
Example 2
Input
height = 5
blacklist = [0]
Output
0
Explanation
There's no way to reach height 0 since it's on the blacklist.





int MOD = 1e9 + 7;
int dfs(int h, unordered_set<int>& black, vector<vector<int>>& dp, int even) {
    if (black.find(h) != black.end() || h < 0) {
        return 0;
    }

    if (h == 0) {
        return 1;
    }

    if (dp[h][even] != -1) {
        return dp[h][even];
    }

    long ans = 0;
    if (even) {
        ans = (ans + dfs(h - 2, black, dp, 1 - even)) % MOD;
    } else {
        ans = (ans + dfs(h - 3, black, dp, 1 - even)) % MOD;
    }
    ans = (ans + dfs(h - 1, black, dp, 1 - even) + dfs(h - 4, black, dp, 1 - even)) % MOD;

    return dp[h][even] = ans;
}

int solve(int h, vector<int>& blacklist) {
    unordered_set<int> black;
    for (int num : blacklist) {
        black.insert(num);
    }

    vector<vector<int>> dp(h + 1, vector<int>(2, -1));
    return dfs(h, black, dp, 1);
}


