309. Best Time to Buy and Sell Stock with Cooldown
Medium

2698

88

Add to List

Share
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]




class Solution {
public:
    int maxProfit(vector<int>& prices) {
int n = prices.size();
if(n < 2)
return 0;

vector<int> buy(n, 0);
vector<int> sell (n, 0);
buy[0] = -prices[0];
        
sell[0] = 0;
sell[1] = max(0, buy[0] + prices[1]);
buy[1] = max(buy[0], 0 - prices[1]);

for(int i = 2; i < n; i++){

    sell[i] = max(buy[i-1] + prices[i], sell[i-1]);

    buy [i] = max(sell[i-2] - prices[i] , buy[i-1]);
}
        
// you can't keep any stock in your hand 
return sell[n-1];
              }
    };
 
