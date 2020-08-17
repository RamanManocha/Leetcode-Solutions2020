
https://www.geeksforgeeks.org/maximum-sum-possible-for-a-sub-sequence-such-that-no-two-elements-appear-at-a-distance-k-in-the-array/



// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the maximum sum possible 
int maxSum(int* arr, int k, int n) 
{ 
	if (n == 0) 
		return 0; 
	if (n == 1) 
		return arr[0]; 
	if (n == 2) 
		return max(arr[0], arr[1]); 

	// dp[i] represent the maximum sum so far 
	// after reaching current position i 
	int dp[n]; 

	// Initialize dp[0] 
	dp[0] = arr[0]; 

	// Initialize the dp values till k since any 
	// two elements included in the sub-sequence 
	// must be atleast k indices apart, and thus 
	// first element and second element 
	// will be k indices apart 
	for (int i = 1; i <= k; i++) 
		dp[i] = max(arr[i], dp[i - 1]); 

	// Fill remaining positions 
	for (int i = k + 1; i < n; i++) 
		dp[i] = max(arr[i], dp[i - (k + 1)] + arr[i]); 

	// Return the maximum sum 
	int max = *(std::max_element(dp, dp + n)); 
	return max; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 6, 7, 1, 3, 8, 2, 4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 2; 
	cout << maxSum(arr, k, n); 

	return 0; 
} 
