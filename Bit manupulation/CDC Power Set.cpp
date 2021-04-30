




Power Set 
Easy Accuracy: 42.07% Submissions: 3877 Points: 2
Given a string S find all possible substrings of the string in lexicographically-sorted order.

Example 1:

Input : str = "abc"
Output: a ab abc ac b bc câ€‹
Explanation : There are 7 substrings that 
can be formed from abc.
Example 2:

Input: str = "aa"
Output: a a aa
Explanation : There are 3 substrings that 
can be formed from aa.
Your Task:
You don't need to read ot print anything. Your task is to complete the function AllPossibleStrings() which takes S as input parameter and returns a list of all possible substrings(non-empty) that can be formed from S in lexicographically-sorted order.
 

Expected Time Complexity: O(2n) where n is the length of the string
Expected Space Complexity : O(n * 2n)
 

Constraints: 
1 <= Length of string <= 16
  
  
  



#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    
		    vector<string> ans;
		    long long int total=pow(2,s.length());
		    for(int i=1;i<total;++i)
		    {
		        string s1;
		        
		        for(int j=0;j<s.length();++j)
		          {
		            if(i & (1<<j))    
		                s1.push_back(s[j]);
		          }
		      
		             ans.push_back(s1);
		    }
		    
		   
		  sort(ans.begin(),ans.end());  
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends



