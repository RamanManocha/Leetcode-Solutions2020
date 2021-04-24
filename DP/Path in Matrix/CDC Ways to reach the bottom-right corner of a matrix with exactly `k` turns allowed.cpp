
Ways to reach the bottom-right corner of a matrix with exactly `k` turns allowed


https://www.techiedelight.com/reach-bottom-right-corner-matrix-exactly-k-turns/


#include <iostream>
using namespace std;
 
// `M × N` matrix
#define M 3
#define N 3
 
// Function to check whether `(i, j)` is a valid matrix coordinate or not
bool isValid(int i, int j) {
    return (i >= 0 && i < M && j >= 0 && j < N);
}
 
// Recursive function to count the number of different ways to reach the last
// cell `(M-1, N-1)` of a matrix from the given cell `(i, j)` with `k` turns left.
// `isCol` flag is true when the current direction is along a column, false otherwise.
 
int totalWays(int i, int j, int k, bool isCol)
{
    // If the number of turns is exhausted or if the cell is invalid
    if (k == -1 || !isValid(i, j)) {
        return 0;
    }
 
    // If the destination is reached with exactly `k` turns
    if (k == 0 && i == M - 1 && j == N - 1) {
        return 1;
    }
 
    // If the current direction is along a column
    if (isCol)
    {
        // 1. Continue moving along the column
        // 2. Turn right and decrement the number of turns by 1
 
        return totalWays(i + 1, j, k, isCol) +
            totalWays(i, j + 1, k - 1, !isCol);
    }
 
    // If the current direction is along a row
    // 1. Continue moving along the row
    // 2. Turn down and decrement the number of turns by 1
 
    return totalWays(i, j + 1, k, isCol) +
        totalWays(i + 1, j, k - 1, !isCol);
}
 
// Function to count the number of different ways to reach the bottom-right corner
// of a matrix from its top-left corner with exactly `k` turns allowed
int totalWays(int i, int j, int k)
{
    return totalWays(i + 1, j, k, true) +   // Recur by moving along a column
        totalWays(i, j + 1, k, false);      // Recur by moving along a row
}
 
int main()
{
    int k = 2;
    cout << "The total number of ways is " << totalWays(0, 0, k);
 
    return 0;
}

