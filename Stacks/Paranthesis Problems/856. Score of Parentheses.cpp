





856. Score of Parentheses
Medium

2158

69

Add to List

Share
Given a balanced parentheses string S, compute the score of the string based on the following rule:

() has score 1
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
 

Example 1:

Input: "()"
Output: 1
Example 2:

Input: "(())"
Output: 2
Example 3:

Input: "()()"
Output: 2
Example 4:

Input: "(()(()))"
Output: 6
 

Note:

S is a balanced parentheses string, containing only ( and ).
2 <= S.length <= 50








  
class Solution {
    
    int dfs(const string& S, int& i) {
        int sum = 0;
        
        for (i; i < S.length(); i++) {
            if (S[i] == '(') {
                i++;
                sum += dfs(S, i);
            } else if (S[i] == ')') {
                if (sum == 0) return 1;
                return 2*sum;
            }
        }
        
        return sum;
    }
    
public:
    int scoreOfParentheses(string S) {
        int i = 0;
        return dfs(S, i);
    }
};
