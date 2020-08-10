131. Palindrome Partitioning
Medium


Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]


The problem has a nice structure that backtracking naturally fits in. The structure is, given a starting position start, we search from start till the end of the string. Once we reach a position i such that the sub-string from start to i (s.substr(start, i - start + 1)) is a palindrome, we add it to a temporary par. Then we recursively call the same function to process the remaining sub-string. Once we reach the end of the string, we add par into the result pars 
of all the possible partitioning.

Then, backtracking happens. Remember that at position i, we find s.substr(start, i - start + 1) to be a palindrome and we 
immediately add it to par. It is obvious that there may be some other position j such that j > i and s.substr(start, j - start + 1) 
  is also a palindrome. So we need to recover to the state before adding s.substr(start, i - start + 1) to par and continue to find
  the next palindrome position after i. And we simply need to pop s.substr(start, i - start + 1) out of par to make things work.

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;
        
        vector<string> path;
        dfs(0, s, path, ret);
        
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
