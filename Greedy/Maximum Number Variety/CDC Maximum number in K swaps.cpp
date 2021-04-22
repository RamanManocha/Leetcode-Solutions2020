




Efficient Solution:
Approach: The above approach traverses the whole string at each recursive call which is highly inefficient and unnecessary. Also, pre-computing the maximum digit after the current at a recursive call avoids unnecessary exchanges with each digit. It can be observed that to make the maximum string, the maximum digit is shifted to the front. So, instead of trying all pairs, try only those pairs where one of the elements is the maximum digit which is not yet swapped to the front. 
There is an improvement by 27580 microseconds for each test case.
Algorithm:  


Create a global variable which will store the maximum string or number.
Define a recursive function that takes the string as a number, the value of k, and the current index.
Find the index of the maximum element in the range current index to end.
if the index of the maximum element is not equal to the current index then decrement the value of k.
  
  
Run a loop from the current index to the end of the array
If the ith digit is equal to the maximum element

Swap the ith and element at the current index and check if the string is now maximum and update the maximum string.
Call the function recursively with parameters: string and k.
Now again swap back the ith and element at the current index.
  
  
  
  
 
// C++ program to find maximum
// integer possible by doing
// at-most K swap operations on
// its digits.
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum
// integer possible by
// doing at-most K swap operations
// on its digits
void findMaximumNum(
    string str, int k,
    string& max, int ctr)
{
    // return if no swaps left
    if (k == 0)
        return;

    int n = str.length();

    // Consider every digit after
    // the cur position
    char maxm = str[ctr];
    for (int j = ctr + 1; j < n; j++) {
        // Find maximum digit greater
        // than at ctr among rest
        if (maxm < str[j])
            maxm = str[j];
    }

    // If maxm is not equal to k,
    // decrement k
    if (maxm != str[ctr])
        --k;

    // search this maximum among the rest
    for (int j = ctr; j < n; j++) {
        // If digit equals maxm swap
        // the digit with current
        // digit and recurse for the rest
        if (str[j] == maxm) {
            // swap str[ctr] with str[j]
            swap(str[ctr], str[j]);

            // If current num is more than
            // maximum so far
            if (str.compare(max) > 0)
                max = str;

            // recurse other swaps after cur
            findMaximumNum(str, k, max, ctr + 1);

            // Backtrack
            swap(str[ctr], str[j]);
        }
    }
}

// Driver code
int main()
{
    string str = "129814999";
    int k = 4;

    string max = str;
    findMaximumNum(str, k, max, 0);

    cout << max << endl;

    return 0;
}
