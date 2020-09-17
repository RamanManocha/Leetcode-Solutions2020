646. Maximum Length of Pair Chain

You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]



class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
    int max=1,i=0;
    sort(pairs.begin(),pairs.end(),[](vector<int> &a,vector<int>&b){
        return a[1]<b[1];
    });
    for(int j=1;j<pairs.size();j++){
    if(pairs[i][1]<pairs[j][0]){
        i=j;
        max++;
    }
    } 
        return max;
    }
};


















// class Solution {
// public:
//     int findLongestChain(vector<vector<int>>& pairs) {
//         if(!pairs.size()) return 0;
//         sort(pairs.begin(), pairs.end());
// 		// LIS array initialized as 1. As, every element is itself an answer
//         vector<int> lis(pairs.size(), 1);
//         int longestChainNum = 1;
// 		// Finding LIS in [0-----j]i for each 'i'
//         for(int i=1;i<pairs.size();i++){
//             for(int j=0;j<i;j++){
// 				// Condition similar to LIS
//                 if((pairs[j][1] < pairs[i][0]) && (lis[i] < lis[j] + 1)){
//                     lis[i] = lis[j] + 1;
// 					// Updating maximum
//                     longestChainNum = max(longestChainNum, lis[i]);
//                 }
//             }
//         }
//         return longestChainNum;
//     }
// };


// class Solution {
// public:
    
//     static bool cmp(vector<int>&a,vector<int>&b){
//         return a[0]<b[0];
//     }
    
    
    
//     int findLongestChain(vector<vector<int>>& pairs) {
        
//         int n = pairs.size();
//         if(n<2)return n;
//         vector<int> dp(n,1);
//         int ans = 0;
//         sort(pairs.begin(),pairs.end(),cmp);
//         for(int i=1;i<n;i++){
//             for(int j=0;j<i;j++){
//                 if(pairs[i][0]>pairs[j][1]){
//                     dp[i] = max(dp[i],dp[j]+1);
//                 }
//             }
//             ans = max(ans,dp[i]);
//         }
//         return ans;
//     }
// };
