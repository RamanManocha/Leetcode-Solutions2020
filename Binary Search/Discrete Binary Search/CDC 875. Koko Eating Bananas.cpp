


875. Koko Eating Bananas
Medium

1449

87

Add to List



Share
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109











// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
        
//     }
// };


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left=0;
        int right=0;
        for(int i=0;i<piles.size();i++)
        {
            right=max(right,piles[i]);
        }
        left=1;
        int ans=right;
        while(left<right)
        {
            int mid=(left+(right-left)/2);
            int hours=nmber_of_hors(piles,mid);
            if(hours>H)//that means we have to increase eat rate so left = mid+1
            {
                left=mid+1;
              
               
            }
            else// that means we have to find minimum k ,so right=mid
            {
               
                right=mid ;
                 ans= right;

            }
        }
        return ans;
    }
    int nmber_of_hors(vector<int>& piles,int K)
    {
        int hours=0;
        for(int i=0;i<piles.size();i++)
        {
            hours+=(piles[i]/K);
            if(piles[i]%K!=0) hours++;// this is for ceil 
        }
        return hours;
    }
};
