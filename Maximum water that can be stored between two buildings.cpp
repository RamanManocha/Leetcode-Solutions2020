Given an integer array which represents the heights of N buildings, the task is to delete N-2 buildings such that the water that can be trapped between the 
remaining two building is maximum. Please note that the total water trapped between two buildings is gap between them (number of buildings removed) multiplied by height of 
the smaller buildings




// CPP implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Return the maximum water that can be stored 
int maxWater(int height[], int n) 
{ 
	int maximum = 0; 

	// Check all possible pairs of buildings 
	for (int i = 0; i < n - 1; i++) { 
		for (int j = i + 1; j < n; j++) { 
			int current = (min(height[i], 
							height[j]) 
						* (j - i - 1)); 

			// Maximum so far 
			maximum = max(maximum, current); 
		} 
	} 
	return maximum; 
} 

// Driver code 
int main() 
{ 
	int height[] = { 2, 1, 3, 4, 6, 5 }; 
	int n = sizeof(height) / sizeof(height[0]); 
	cout << maxWater(height, n); 
	return 0; 
} 

// This code is contributed by ihritik 




