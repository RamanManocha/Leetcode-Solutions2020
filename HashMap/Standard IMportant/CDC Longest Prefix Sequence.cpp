



Longest Prefix Sequence
You are given a list of lowercase alphabet strings words. Return the length of the longest sequence of words where each previous word is the prefix of the next word and the next word has just one new character appended. You can rearrange words in any order.

Constraints

0 ≤ n ≤ 100,000 where n is the length of words
1 ≤ m ≤ 100,000 where m is the length of the longest string in words
Example 1
Input
words = ["abc", "ab", "x", "xy", "abcd"]
Output
3
Explanation
We can form the following sequence: ["ab", "abc", "abcd"].





int solve(vector<string>& words) {
    sort(words.begin(), words.end());
    map<string, int> mp;
    int ret = 1;
    for (auto& word : words) {
        string tmp = word;
        cout << tmp << " ";
        // removing last character from string
        tmp.pop_back();

        if (mp.count(tmp))
            mp[word] = mp[tmp] + 1;
        else
            mp[word] = 1;
        ret = max(ret, mp[word]);
    }
    return ret;
}

