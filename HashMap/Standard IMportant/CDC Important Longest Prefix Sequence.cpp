



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




    
    struct Node {
    bool end;
    vector<Node*> children;

    Node() {
        end = false;
        children.assign(26, NULL);
    }
};

Node* root;
int res;

void add_word(string w) {
    Node* tmp = root;
    for (int i = 0; i < w.size(); i++) {
        int c = (int)(w[i] - 'a');
        if (tmp->children[c] == NULL) tmp->children[c] = new Node();
        tmp = tmp->children[c];
    }
    tmp->end = true;
}

int longest(Node* cur) {
    if (cur == NULL) return 0;
    int length = cur->end ? 1 : 0;
    int sublength = 0;
    for (int i = 0; i < 26; i++) {
        sublength = max(sublength, longest(cur->children[i]));
    }
    res = max(res, length + sublength);
    return length + sublength;
}
int solve(vector<string>& words) {
    res = 0;
    root = new Node();
    for (string w : words) add_word(w);
    longest(root);
    return res;
}





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

