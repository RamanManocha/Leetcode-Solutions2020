1235. Maximum Profit in Job Scheduling

Share
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime , endTime and profit arrays, you need to output the maximum profit you can take such that there are no 2 jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Example 1:



Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:




Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.1235. Maximum Profit in Job Scheduling
Hard

621

8

Add to List

Share
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime , endTime and profit arrays, you need to output the maximum profit you can take such that there are no 2 jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

 

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
Example 2:




Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job. 
Profit obtained 150 = 20 + 70 + 60.








class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs; // {start time, end time, profit}
        for (int i = 0; i < startTime.size(); i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end(), [](const vector<int>& v1, const vector<int>& v2){
            return v1[1] < v2[1];
        });

        int n = jobs.size();
        vector<int> dp(n, 0);
        
        dp[0] = jobs[0][2];
        for (int i = 1; i < n; i++){
            // take jobs[i]
            int takeCurr = jobs[i][2];
            int idx = lastSmallerOrEqual(jobs, i, jobs[i][0]);
            if (jobs[idx][1] <= jobs[i][0])
                takeCurr += dp[idx];
            
            // no take jobs[i]
            int noTakeCurr = dp[i - 1];
            
            dp[i] = max(takeCurr, noTakeCurr);
        } 
        return dp[n - 1];
    }
    
    int lastSmallerOrEqual(const vector<vector<int>>& jobs, int idx, int start_time){
        int left = 0, right = idx - 1;
        while(left < right){
            int mid = left + (right - left + 1) / 2;
            if (jobs[mid][1] <= start_time)
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};
