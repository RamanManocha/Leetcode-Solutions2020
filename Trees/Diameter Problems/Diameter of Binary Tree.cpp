543. Diameter of Binary Tree
Easy

3282

202

Add to List

Share
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].








class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // Check if tree exists
        if (root == NULL) return 0;
        int diam = 0;
        // Find depths of left and right subtrees
        int leftDepth = helper(root->left, diam);
        int rightDepth = helper(root->right, diam);
        
        // Return largest diameter (maybe not through root)
        return max(diam, leftDepth + rightDepth);
    }
    
    // Recursive DFS method
    int helper(TreeNode* root, int &diam) {
        // Check for leaf node
        if (root == NULL) return 0;
        
        // Find depths of left and right subtrees
        int leftDepth = helper(root->left, diam);
        int rightDepth = helper(root->right, diam);
        
        // Diameter is the number of edges between the farthest nodes
        diam = max(diam, leftDepth + rightDepth);
        // Return the depth of the current subtree
        return max(leftDepth, rightDepth) + 1;
    }
};

