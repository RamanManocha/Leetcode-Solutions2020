
991. Broken Calculator


On a broken calculator that has a number showing on its display, we can perform two operations:

Double: Multiply the number on the display by 2, or;
Decrement: Subtract 1 from the number on the display.
Initially, the calculator is displaying the number X.

Return the minimum number of operations needed to display the number Y.

 

Example 1:

Input: X = 2, Y = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
Example 2:

Input: X = 5, Y = 8
Output: 2
Explanation: Use decrement and then double {5 -> 4 -> 8}.





/* Initially, I am thinking about using BFS.. but the solution will easily get TLE...
 * Later, after analyze the problem in detail, 
 * I found:
 * (1) when X > Y... multiple by 2 will only bring us far away from target...
 *     so each step, we can only subtract 1 from X to get the target value...
 *     thus we just need to return X - Y;
 * (2) when Y > X... we can think reversely...
 *     we can achieve Y from the previous number by either of two cases 
 *     (a) pre - 1 = Y;
 *     (b) pre * 2 = Y...
 *     which step to take is dependent on if Y is even or odd...
 *     if (Y is even), pre = Y / 2;
 *     if (Y is odd), pre = Y + 1...
 *     then we reset Y as pre...
 *     do the same thing, until Y <= X... which is the first case...
 *         
 */

class Solution {
    public int brokenCalc(int X, int Y) {
        int cnt = 0;
        while (Y > X) {
            if ((Y & 1) == 1) {
                Y += 1;
                cnt++;
            } 
            Y >>= 1;
            cnt++;
        }  // this is to deal with the case when x > y
        return cnt + (X - Y);
    }
}
