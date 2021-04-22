

Largest number in K swaps 


Medium Accuracy: 31.96% Submissions: 5883 Points: 4
  
  
Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations
on the digits of str at most K times.


Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5
Example 2:

Input:
K = 3
str = "3435335"
Output:
5543333
Explanation:
Three swaps can make the input
3435335 to 5543333, swapping 3 
with 5, 4 with 5 and finally 3 with 4 

Your task:
You don't have to read input or print anything. Your task is to complete the function findMaximumNum() which takes the string and an 
 integer as input and returns a string containing the largest number formed by perfoming the swap operation at most k times.
  
 
  
  
  
  
  
Naive Solution:
Approach: The idea is to consider every digit and swap it with digits following it one at a time and see if it leads to the maximum number. 
  The process is repeated K times. The code can be further optimized, if the current digit is swapped with a digit less than the following 
  digit.
Algorithm:  


Create a global variable which will store the maximum string or number.
Define a recursive function that takes the string as number and value of k
Run a nested loop, the outer loop from 0 to length of string -1 and inner loop from i+1 to end of the string.
Swap the ith and jth character and check if the string is now maximum and update the maximum string.
Call the function recursively with parameters: string and k-1.
Now again swap back the ith and jth character.

  
  
  
  
  
// C++ program to find maximum
// integer possible by doing
// at-most K swap operations
// on its digits.
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum
// integer possible by
// doing at-most K swap
// operations on its digits
void findMaximumNum(
    string str, int k, string& max)
{
    // Return if no swaps left
    if (k == 0)
        return;

    int n = str.length();

    // Consider every digit
    for (int i = 0; i < n - 1; i++) {

        // Compare it with all digits after it
        for (int j = i + 1; j < n; j++) {
            // if digit at position i
            // is less than digit
            // at position j, swap it
            // and check for maximum
            // number so far and recurse
            // for remaining swaps
            if (str[i] < str[j]) {
                // swap str[i] with str[j]
                swap(str[i], str[j]);

                // If current num is more
                // than maximum so far
                if (str.compare(max) > 0)
                    max = str;

                // recurse of the other k - 1 swaps
                findMaximumNum(str, k - 1, max);

                // Backtrack
                swap(str[i], str[j]);
            }
        }
    }
}

// Driver code
int main()
{
    string str = "129814999";

    int k = 4;

    string max = str;
    findMaximumNum(str, k, max);

    cout << max << endl;

    return 0;
}

  
  
  
  
  
  
  


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
