



294. Flip Game II
Medium

457

39

Add to List

Share
You are playing a Flip Game with your friend.

You are given a string currentState that contains only '+' and '-'. You and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move, and therefore the other person will be the winner.

Return true if the starting player can guarantee a win, and false otherwise.

 

Example 1:

Input: currentState = "++++"
Output: true
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
Example 2:

Input: currentState = "+"
Output: false
 

Constraints:

1 <= currentState.length <= 60
currentState[i] is either '+' or '-'.
 

Follow up: Derive your algorithm's runtime complexity






class Solution {
public:
 bool canWin(string s) {
    if (s.size() == 0) {
        return false;
    }
    
    bool isMoved = false;
    for (size_t i = 0; i < s.size() - 1; ++i) {
        if (s[i] == '+' && s[i + 1] == '+') {
            isMoved = true;
            s[i] = '-';
            s[i + 1] = '-';
            if (!canWin(s)) {
                return true;
            }
            s[i] = '+';
            s[i + 1] = '+';
        }
    }
    
    if (!isMoved) {
        return false;
    }
}
};
