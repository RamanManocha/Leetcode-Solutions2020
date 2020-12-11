


241. Different Ways to Add Parentheses
Medium

1928

101

Add to List

Share
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10




// class Solution {
// public:
//     vector<int> diffWaysToCompute(string input) {
//         int size=input.size();
//         vector<int> result;
//         for(int i=0; i<size; i++){
//             if(input[i] == '+' || input[i] == '*' || input[i] == '-') {
                
//                 for(int a : diffWaysToCompute(input.substr(0, i)))
//                     for(int b : diffWaysToCompute(input.substr(i+1))){
                        
//                         if(input[i]=='+')  result.push_back(a+b);
//                         if(input[i]=='-')  result.push_back(a-b);
//                         if(input[i]=='*')  result.push_back(a*b);
//                     }
//             }
//         }
//         /*** the base case is that there are no operator-char ***/
//         /*** we return vector<int>{stoi(input)} when this happens ***/
//         return result.size() ? result : vector<int>{stoi(input)};
//     }
// };



class Solution {
private:
    unordered_map<string, vector<int>>memo;
public:
    vector<int> diffWaysToCompute(string input) {
        
        // Base case 
        
        if (input.empty()) return {};
        unordered_map<string, vector<int>>memo;
        vector<int> result;
        return helper(input, memo, result);
    }
    
    vector<int> helper(string input, unordered_map<string, vector<int>>&memo, vector<int>&res){
        if (input.empty()) return vector<int>{};
        if (memo.find(input) != memo.end()) return memo[input];
        
        vector<int>result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1 = helper(input.substr(0, i), memo, res);
                vector<int> result2 = helper(input.substr(i+1), memo, res);
                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);    
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty()) result.push_back(stoi(input));
        
        memo[input] = result;
        return result;
    }
};
