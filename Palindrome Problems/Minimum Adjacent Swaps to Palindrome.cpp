

https://www.geeksforgeeks.org/count-minimum-swap-to-make-string-palindrome/

Minimum Adjacent Swaps to Palindrome



Given a string s, return the minimum number of adjacent swaps required to convert it into a palindrome. If it's not possible, return -1.

Constraints

n ≤ 1,000 where n is length of s.
Example 1
Input
s = "aabb"
Output
2
Explanation
We can swap the middle "a" and "b" and then swap the first two "a" and "b" to get "baab".









//  * Algorithm:
//      *     1. First check the given string is a jumbled/shuffled palindrome or not.
//      *     2. Next have two pointers p1 at 0 and p2 at s.length - 1 and start iterating.
//      *     3. If chars at both the pointers are same then just shrink the window (increase the p1 and decrease the p2).
//      *     4. or Else
//      *          a. find the matching pair and swap the char to p2 index (increase swap count while swapping) and finally shrink the window.
//      *          b. if not found just swap once with adjacent index and increase the swap count (do not shrink the window here)
//      *     5. Print the Swap Count
//      *
//      * Time Complexity: O(n) to find Palindrome + [ O(n) for two pointer iteration * O(n) for checking and swapping ] so => O(n^2)
//      * Space Complexity: O(n)








bool couldBeP(string s) {
    map<char, int> res;
    for (auto v:s) {
        res[v]++;
    }
    auto it=res.begin();
    int signle=0;
    while(it!=res.end()) {
        if (it->second%2!=0) {
            signle++;
        }
        it++;
    }
    return signle<=1;
}

int minswap(string s) {
    if (!couldBeP(s)) return -1;
    int len = s.size();
    int l =0;
    int r =len-1;
    int sc = 0;
    int k=r;
    while (l<r) {
        k=r;
        while (k>=l && s[l]!=s[k]) {
            k--;
        }
        if (l!=k && s[l]==s[k]) {
            while (k<r) {
                swap(s[k], s[k+1]);
                k++;
                sc++;
            }
            r--;
            l++;
        } else {
            swap(s[l],s[l+1] );
            sc++;
        }
    }
    //std::cout<<"ms----: "<<s<<endl;
    return sc;
}


int main() {
    string s1 = "abaabab"; 
    std::cout << minswap(s1)<<std::endl;
    string s2 = "mamad"; 
    std::cout<< minswap(s2)<<std::endl;
    string s3 = "ntiin";
    std::cout<<minswap(s3)<<std::endl;  
}
