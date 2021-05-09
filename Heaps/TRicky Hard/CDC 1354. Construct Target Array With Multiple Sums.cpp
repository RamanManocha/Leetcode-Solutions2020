

https://www.youtube.com/watch?v=iZeCKyT6PMg&ab_channel=AdityaMahajanAdityaMahajan




1354. Construct Target Array With Multiple Sums
Hard

412

54

Add to List

Share
Given an array of integers target. From a starting array, A consisting of all 1's, you may perform the following procedure :

let x be the sum of all elements currently in your array.
choose index i, such that 0 <= i < target.size and set the value of A at index i to x.
You may repeat this procedure as many times as needed.
Return True if it is possible to construct the target array from A otherwise return False.

 

Example 1:

Input: target = [9,3,5]
Output: true
Explanation: Start with [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
Example 2:

Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].
Example 3:

Input: target = [8,5]
Output: true
 

Constraints:

N == target.length
1 <= target.length <= 5 * 10^4
1 <= target[i] <= 10^9




class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(size(target) == 1) 
            return target[0] == 1;

        long sum=0;
        for(int i=0;i<target.size();i++)
            sum += target[i];

        priority_queue<int> pq(begin(target), end(target));

        // Repeat till all elements haven't been made equal to 1
        while(pq.top() != 1) {  

            long largest = pq.top(); pq.pop();
            long largest_2 = pq.top();
            long restArrSum = sum - largest;

            // n = number of subtraction to get largest below 2nd largest element. 
            // max(1, ..) denotes teh case where largest and largest_2 are equal
            int n = max(1l, (largest - largest_2) / restArrSum);

            // subtracting from largest n times
            largest -= (restArrSum * n); 

            // push element back & update the sum of array
            pq.push(largest);            
            sum = restArrSum + largest;

            // if an element gets below 1, we cant achieve original array
            if(largest < 1) return false;
        }
        return true;
    }
};
