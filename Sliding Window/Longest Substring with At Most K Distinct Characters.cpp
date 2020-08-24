340. Longest Substring with At Most K Distinct Characters
Hard



Share
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.
Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.



class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int res = 0;
        for(int i = 0, j = 0; j < s.size(); j++){
            if(mp.find(s[j]) == mp.end()){
                mp[s[j]] =  1;
            }else{
                mp[s[j]]++;
            }
            
            while(mp.size() > k){
                if(mp[s[i]] > 1){
                    mp[s[i]]--;
                }else{
                    mp.erase(s[i]);
                }
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};


