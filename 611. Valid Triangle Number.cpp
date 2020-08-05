Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].



class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, temp = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int j = i+1;
           int  k = j;
            while(j < n && k < n){
                if(j == k) k++;
                else{
                    if(nums[i] + nums[j] > nums[k]) res += k - j, k++;
                    else j++;   
                }
                
            } 
        }
        return res;
        
    }
};


