
1478. Allocate Mailboxes
Hard

386

6

Add to List

Share
Given the array houses and an integer k. where houses[i] is the location of the ith house along a street, your task is to allocate k mailboxes in the street.

Return the minimum total distance between each house and its nearest mailbox.

The answer is guaranteed to fit in a 32-bit signed integer.

 

Example 1:



Input: houses = [1,4,8,10,20], k = 3
Output: 5
Explanation: Allocate mailboxes in position 3, 9 and 20.
Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 
Example 2:



Input: houses = [2,3,5,12,18], k = 2
Output: 9
Explanation: Allocate mailboxes in position 3 and 14.
Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.
Example 3:

Input: houses = [7,4,6,1], k = 1
Output: 8
Example 4:

Input: houses = [3,6,14,10], k = 4
Output: 0
 

Constraints:

n == houses.length
1 <= n <= 100
1 <= houses[i] <= 10^4
1 <= k <= n
Array houses contain unique integers.







class Solution {
public:
    int cost[101][101];
    int dp[101][101];
    
    int ok(vector<int>& houses , int k , int start){
        int n=houses.size();
        if(k==0 && start==n) return 0;
        if(k==0 || start==n) return 1e7;
        if(dp[k][start]!=-1) return dp[k][start];
        int ans=1e7;
        for(int i=start;i<n;i++){
            ans=min(ans,cost[start][i]+ok(houses,k-1,i+1));
        }
        return dp[k][start]=ans;
    }
    
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        int n=houses.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int x=i;x<=j;x++){
                    cost[i][j]+=abs(houses[(i+j)/2]-houses[x]);
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        return ok(houses,k,0);
    }
};
