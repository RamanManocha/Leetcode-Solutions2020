



1120. Maximum Average Subtree
Medium

412

14

Add to List

Share
Given the root of a binary tree, find the maximum average value of any subtree of that tree.

(A subtree of a tree is any node of that tree plus all its descendants. The average value of a tree is the sum of its values, divided by the number of nodes.)

 

Example 1:



Input: [5,6,1]
Output: 6.00000
Explanation: 
For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
For the node with value = 6 we have an average of 6 / 1 = 6.
For the node with value = 1 we have an average of 1 / 1 = 1.
So the answer is 6 which is the maximum.
 

Note:

The number of nodes in the tree is between 1 and 5000.
Each node will have a value between 0 and 100000.
Answers will be accepted as correct if they are within 10^-5 of the correct answer.






class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        double result = 0;
        helper(root,result);
        return result;
    }
    
    pair<double,int> helper(TreeNode* root,double& max)
    {
        if(!root)
        {
            return {0,0};
        }
        pair<double,int> sum;
        auto left = helper(root->left,max);
        auto right = helper(root->right,max);
        sum.first = left.first+right.first+root->val;
        sum.second = left.second+right.second+1;
        auto res = sum.first/sum.second;
        max = std::max(max,res);
        return sum;
    }
};
