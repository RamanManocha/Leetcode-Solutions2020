

https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/




1780. Check if Number is a Sum of Powers of Three
Medium

204

8

Add to List

Share
Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.

 

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 31 + 32
Example 2:

Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34
Example 3:

Input: n = 21
Output: false
 

Constraints:

1 <= n <= 107





class Solution {
public:   
    bool checkPowersOfThree(int n) {
        if(n==1)
            return true;
        if(n%3==2)
            return false;
        return checkPowersOfThree(n/3);
    }
};


class Solution {
public:
    bool checkPowersOfThree(int n) {
         while (n > 1 && n % 3 != 2) {
            if (n % 3 == 0) {
                n /= 3;
            }else {
                --n;
            }
        }
        return n == 1;
    } 
};
