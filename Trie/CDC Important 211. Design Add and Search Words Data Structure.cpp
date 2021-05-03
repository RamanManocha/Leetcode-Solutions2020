211. Design Add and Search Words Data Structure


Add to List

Share
You should design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) adds word to the data structure, it can be matched later.
bool search(word) returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search 



Beeest Baaaaap Approach

class WordDictionary {
public:
    struct TrieNode{
    public:
        bool isEnd;
        TrieNode* child[26];
        TrieNode(){
            isEnd=false;
             memset(child, NULL, sizeof(child));;
        }
    };
    WordDictionary(){
        root=new TrieNode();
        root->isEnd=true;
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *tmp=root;
        for(int i=0;i<word.length();++i){
            if(tmp->child[word[i]-'a']==NULL){
                tmp->child[word[i]-'a']=new TrieNode();
            }
            tmp=tmp->child[word[i]-'a'];
        }
        tmp->isEnd=true;
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word,root,0);
    }
    bool searchWord(string word,TrieNode* node,int s){
        if(s==word.length())return node->isEnd;
        if(word[s]=='.'){
            for(int i=0;i<26;++i){
                if(node->child[i] && searchWord(word,node->child[i],s+1))return true;
            }
            return false;
        }else{
            return (node->child[word[s]-'a'] && searchWord(word,node->child[word[s]-'a'],s+1));
        }
    }
private:
    TrieNode *root;
};







Simple Approach



// Trie Solution provided
class TrieNode{
  public:
    bool isEnd;
	vector<TrieNode*> dict;
    TrieNode(){
        isEnd = false;
        dict.resize(26,nullptr);
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
	// Addition of word in the trie is fairly simple.
	// If you are not able to understand it, then solve the below question first :
	// https://leetcode.com/problems/implement-trie-prefix-tree/
    void addWord(string word) {
        TrieNode* itr = root;
        for(int i=0;i<word.length();i++){
            if(itr->dict[word[i]-'a']==nullptr){
                itr->dict[word[i]-'a'] = new TrieNode();
            }
            itr = itr->dict[word[i]-'a'];
        }
        itr->isEnd = true;
    }


	// Recursive function for searching the string in the trie.
    bool func(TrieNode* root, string word, int pos){
		// When pos becomes equal to length of the word i.e. we are at the end of the string.
        if(word.length()==pos){
			// If the string is present in the trie then "root" will be at the end of the trie.
            if(root->isEnd)
                return true;
            return false;
        }
		// If the character is not '.' then it is fairly simple.
		// We just need to check whether the word[pos] is present in the trie or not.
        if(word[pos]!='.'){
            if(root->dict[word[pos]-'a']!=nullptr)
                return func(root->dict[word[pos]-'a'], word,pos+1);
            else
                return false;
        }
        else{
			// Now, if we encounter '.' then we need to check every possible alphabet i.e. from a-z
			// If we find any alphabet which is present in the trie,
			// then we have to make the recursive call to the function with now --> pos + 1.
			// If we encounter null node then we will continue and check the rest of the alphabets.
            for(int i=0;i<26;i++){
                if(root->dict[i]==nullptr)
                    continue;
                else{
                    if(func(root->dict[i],word,pos+1))
                        return true;
                }
            }
        }
		// If after checking everything, we don't find the alphabet in the trie ->
        return false;
    }
    bool search(string word) {
        return func(root, word, 0);
    }
};








