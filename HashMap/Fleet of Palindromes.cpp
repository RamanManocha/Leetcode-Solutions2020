Fleet of Palindromes
Given a lowercase alphabet string s and an integer k, return whether we can create k palindromes using all characters in s.

Constraints

0 ≤ n ≤ 100,000 where n is length of s.
Example 1
Input
s = "racelevelcar"
k = 2
Output
true
Explanation
We can make "racecar" and "level"

Example 2
Input
s = "dog"
k = 2
Output
false
Explanation
We can't make any 2-letter palindromes with the letters given.

Example 3
Input
s = "dog"
k = 3
Output
true
Explanation
Each letter is a palindrome: "d", "o", "g".


bool solve(string s, int k) {
    int odds = 0;
    int tbl[26] = {0};
    for (char c : s) {
        if (++tbl[c - 'a'] % 2)
            odds++;
        else
            odds--;
    }
    return odds <= k && s.size() >= k;
}
