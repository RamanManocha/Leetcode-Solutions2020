
44. Wildcard Matching

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.





class Solution {
public:
    bool isMatch(string s, string p) {
	int m=s.size(), n=p.size();
      bool dp[m+1][n+1];  
        for(int i = 0;i<=m;i++) {
            for(int j = 0;j<=n;j++) {
                dp[i][j] = false;
            }
        }
	dp[0][0] = true;
	for (int i=1; i<=m; i++) {
		dp[i][0] = false;
	}
	for(int j=1; j<=n; j++) {
		if(p[j-1]=='*'){
			dp[0][j] = true;
		} else {
			break;
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if (p[j-1]!='*') {
				dp[i][j] = dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='?');
			} else {
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			}
		}
	}
	return dp[m][n];
}          
        };
