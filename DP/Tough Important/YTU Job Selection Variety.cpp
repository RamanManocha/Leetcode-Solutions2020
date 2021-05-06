
 Find Minimum Time to Finish All Jobs
 
 
 


We can translate this question to:

Verify a given working time limit for every worker, so that all the jobs can be successfully assigned.
We need to find the min possible solution of the above working time limit.

Obviously, every worker has to be assigned for at least one job, so the lower bound is the most time consuming job
and the upper bound can be set to the sum of all jobs. Then we can do a binary search on working time limit.

We use dfs to verify whether a working time limit is valid, the idea is almost the same as https://leetcode.com/problems/partition-to-k-equal-sum-subsets/





 1723. Find Minimum Time to Finish All Jobs


Hard

230

11

Add to List

Share
You are given an integer array jobs, where jobs[i] is the amount of time it takes to complete the ith job.

There are k workers that you can assign jobs to. Each job should be assigned to exactly one worker. The working time of a worker is the sum of the time it takes to complete all jobs assigned to them. Your goal is to devise an optimal assignment such that the maximum working time of any worker is minimized.

Return the minimum possible maximum working time of any assignment.

 

Example 1:

Input: jobs = [3,2,3], k = 3
Output: 3
Explanation: By assigning each person one job, the maximum time is 3.
Example 2:

Input: jobs = [1,2,4,7,8], k = 2
Output: 11
Explanation: Assign the jobs the following way:
Worker 1: 1, 2, 8 (working time = 1 + 2 + 8 = 11)
Worker 2: 4, 7 (working time = 4 + 7 = 11)
The maximum working time is 11.
 

Constraints:

1 <= k <= jobs.length <= 12
1 <= jobs[i] <= 107
  
  
  
 
 
 
 // class Solution {
// public:
//     int minimumTimeRequired(vector<int>& jobs, int k) {
        
//     }
// };

// We can translate this question to:

// Verify a given working time limit for every worker, so that all the jobs can be successfully assigned.
// We need to find the min possible solution of the above working time limit.

// Obviously, every worker has to be assigned for at least one job, so the lower bound is the most time consuming job
// and the upper bound can be set to the sum of all jobs. Then we can do a binary search on working time limit.

// We use dfs to verify whether a working time limit is valid, the idea is almost the same as https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int sum = 0;
        for(int j:jobs)
            sum += j;
        sort(jobs.begin(),jobs.end(),greater<int>());
        int l = jobs[0], r = sum;
        while(l<=r){
            int mid = (l+r)>>1;
            vector<int> worker(k,0);
            if(dfs(jobs,worker,0,mid))
                r = mid -1;
            else
                l = mid + 1;
        }
        return l;
    }
  
  YTU 
    bool dfs(vector<int>& jobs, vector<int>& worker, int step, int target){
        if(step>=jobs.size())
            return true;
        int cur = jobs[step];
        // assign cur to worker i 
        for(int i=0;i<worker.size();i++){
            if(worker[i] + cur <= target){
                worker[i] += cur;
                if(dfs(jobs,worker,step+1,target))
                    return true;
                worker[i] -= cur;
            }
            if(worker[i]==0)
                break;
        }
        return false;
    }
};











