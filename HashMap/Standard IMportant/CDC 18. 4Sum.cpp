



18. 4Sum
Medium

3260

413

Add to List

Share
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       // T = O(n^3) & S = O(1)
        vector<vector<int>> res; // creating a result vector
        if(nums.empty()) { // If no element in given vector then empty vector iss returned
            return res;
        }
        int n = nums.size();  // size of given vector
        sort(nums.begin(), nums.end());  // sort the array in O(nlog(n)) for optimizing solution
        
        for(int i = 0; i < n; i++) {    // i pointer from 0 to n
            for(int j = i+1; j < n; j++) {  // j pointer from i+1 to n
                int rem = target - nums[i] - nums[j]; // remaining value to find
                int front = j+1;   // left pointer  just after j
                int back = n-1;    // right pointer at last index
                
                while(front < back) { // loop till front and back pointer donot cross over
                    int two_sum = nums[front] + nums[back]; // now come to two sum problem where we need to check for rem
                    if(two_sum < rem) front++;  // if(rem > two_sum) then logically we have to move front pointer ahead to increase value close to rem
                               
                    else if(two_sum > rem) back--; // if(rem < two_sum) then logically move back pointer to back to minimise value to come closer to rem value 
                    
                    else {           // if (rem == two_sum) then we got the quadruplet (i, j, front, back indexed values)
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        res.push_back(quadruplet);
                        
                        // processing the duplicates of number 3
                        while(front < back && nums[front] == quadruplet[2]) ++front;
                        
                        // processing the duplicates of number 4
                        while(front < back && nums[back] == quadruplet[3]) --back;
                    }
                }
                // processing the duplicates of number 2
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
             // processing the duplicates of number 1
                while(i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return res;
    }
   
};



 
