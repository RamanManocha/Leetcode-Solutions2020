


Very Very Important CDC 




792. Number of Matching Subsequences
Medium

1248

89

Add to List

Share
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].






/*
       Create a map that stores indices for each character a-z in S
       Then for each word, do a binary search for next index for current character in word 
       that is greater than the index we last found for the last character.
       If it doesn't exist, word doesn't exist, otherwise continue to search for word
    */

    int numMatchingSubseq( string S, vector<string>& words ) {
        unordered_map< char, vector<int> > charToIndex;
        for( int i=0; i < S.size(); i++ )
            charToIndex[ S[i] ].push_back( i );
            
        int result = 0;
        for( auto word : words ) {
            int isSubSeq = true;
            int pos = -1;
            for( auto c : word ) {
                auto it = upper_bound( charToIndex[c].begin(), charToIndex[c].end(), pos );
				if( it == charToIndex[c].end() )
                    isSubSeq = false;
				else 
                    pos = *it;
            }
            
            if( isSubSeq ) ++result;
        }
        return result;
    }


/*
       Create a map that stores indices for each character a-z in S
       Then for each word, do a binary search for next index for current character in word 
       that is greater than the index we last found for the last character.
       If it doesn't exist, word doesn't exist, otherwise continue to search for word
    */

    int numMatchingSubseq( string S, vector<string>& words ) {
        unordered_map< char, vector<int> > charToIndex;
        for( int i=0; i < S.size(); i++ )
            charToIndex[ S[i] ].push_back( i );
            
        int result = 0;
        for( auto word : words ) {
            int isSubSeq = true;
            int pos = -1;
            for( auto c : word ) {
                auto it = upper_bound( charToIndex[c].begin(), charToIndex[c].end(), pos );
				if( it == charToIndex[c].end() )
                    isSubSeq = false;
				else 
                    pos = *it;
            }
            
            if( isSubSeq ) ++result;
        }
        return result;
    }
