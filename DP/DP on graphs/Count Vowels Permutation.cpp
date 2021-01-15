
1220. Count Vowels Permutation
Hard


https://leetcode.com/problems/count-vowels-permutation/


268

49

Add to List

Share
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
Example 3: 

Input: n = 5
Output: 68
 

Constraints:

1 <= n <= 2 * 10^4

Intuition
We have the following statements:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Let

0 -> a, 1 -> e, 2 -> i, 3 -> o, 4 -> u
We have the following graph relationship:

0 -> {1}
1 -> {0,2}
2 -> {0,1,3,4}
3 -> {2,4}
4 -> {0}
Let dp[n][char] denotes the number of strings of length n starting at char.
Hence, dp[n+1][u] = sum of all dp[n][v] such that there is a directed connection from u to v (u -> v).




class Solution {
public:
    
    // a 0 e 1 i 2 o 3 u 4
    long long int mod =1e9+7;
    
    int countVowelPermutation(int n) {
        long long dp[n][5];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<5;i++)
            dp[0][i]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<5;j++){
                if(j==0){
                    dp[i][j]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4])%mod;
                }
                
                if(j==1){
                   dp[i][j]=(dp[i-1][0]+dp[i-1][2])%mod; 
                }
                
                 if(j==2){
                   dp[i][j]=(dp[i-1][1]+dp[i-1][3])%mod; 
                }
                
                 if(j==3){
                   dp[i][j]=(dp[i-1][2])%mod; 
                }
                
                if(j==4){
                   dp[i][j]=(dp[i-1][2]+dp[i-1][3])%mod; 
                }
            }
        }
        return (dp[n-1][0] + dp[n-1][1] + dp[n-1][2] + dp[n-1][3] + dp[n-1][4])%mod;
    }
};
