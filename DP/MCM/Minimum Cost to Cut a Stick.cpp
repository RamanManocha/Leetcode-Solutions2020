So the Question is asking all about to find the total minimum cost after cutting at all the given cut points on the Stick.

A cost is basically the length of the stick at that time when you make a cut at a particular point.

If you look at the question So What you will try to think You will make the first cut at some place and then second and then third cut till all the cuts. Ordering does not matters when you are cutting at any point.

But Try to think it in the the opposite manner.
Suppose you Cut your stick at all the cuts given to you.
Now what is left with you just some sticks of different lengths.

Now Try to merge these sticks. Instead of cutting, start joinng at given cut points. But you can't merge any two smaller sticks. When you are joining you have two merge so that you get the original stick. Means you cant join the stick in any order.

Suppose your stick is like: |---------|-----------|-----------|---------|
all points in your sticks are :[0 ,1 ,2 ,3, 4]
cut points =[2,3]

when you cut at 2 and 3 your final sticks will be like:
[0,2] ; [2,3] ; [3,4]

So What I was saying is like you cant merge [0,2] and [3,4] first and then merge it with [2,3].

Now what you have wtih you is the sticks after you have applied all the cuts.
Now If you look at this properly You have to
Find the total minimum cost to merge all the sticks into a single stick. But at a time you can mege any two Adjacent Sticks.

When You will merge you will then compute the cost by taking total length of both the sticks you are merging.

Now You have to Start finding the Solution using the answers of the Smaller Sub Problems.

Try finding the answer for every i to j.

Our dp[i][j] represents the total minimum cost after joining all the cut points between i to j because end points does not signify any thing.

For any rannge [i,j] valid cuts are only between i to j do not include i and j in your cuts.
Just At every cut in a range just start joining the sticks and start storing the answer between the range [i,j].

Here We will fill our Dp in a diagonal Manner As the Subproblems are in the form of Ranges.

If you have not done this kind of questions before and dont know how it works I would recommed you to solve
Longest Palindromic Substring using Dp in a Bottom Up Manner.

class Solution
{  
public:

    int minCost(int n, vector<int>& cuts)
    {
        
     //inserting 0 and n as at end points cuts does not signify anything just to 
     //get the length when we are merging.
     cuts.push_back(0); 
     cuts.push_back(n);
        
     //sorting is for so that the you cut your stick in the order
     sort(cuts.begin(),cuts.end());
     
     //dp[i][j] stores the minimum cost  after joining at all the the cuts between i to j
     vector<vector<int> > dp(cuts.size(),vector<int> (cuts.size(),INT_MAX));
    
	// Your base cases stores the answer between [i.i]  and [i][i+1] subarrays or ranges, of size 2 only
     for(int i=0;i<dp.size();i++) dp[i][i]=0;  // base cases as for a point cost is Zero
     for(int i=0;i<dp.size()-1;i++)  dp[i][i+1]=0; //for every two points which constitue a stick is also zero
	 
       
        
     for(int j=2;j<dp.size();j++)
     {
      for(int i=0;i<dp.size()-j;i++)   
      {
        int col=i+j; // your current column
        for(int k=i+1;k<col;k++) //cutting at every k between i to j
        {
         dp[i][col]=min(dp[i][col],dp[i][k]+dp[k][col]+(cuts[col]-cuts[i]));         //adding the final length after your merge            
        }
        }
     }
        
      
     return dp[0][dp.size()-1];   // final answer after joining all the sticks.
        
    }
    

};
