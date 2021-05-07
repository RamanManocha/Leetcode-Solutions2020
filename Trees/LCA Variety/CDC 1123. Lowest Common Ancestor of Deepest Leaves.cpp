


https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/


1123. Lowest Common Ancestor of Deepest Leaves
Medium

690

637

Add to List

Share
Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
Note: This question is the same as 865: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
 

Constraints:

The number of nodes in the tree will be in the range [1, 1000].
0 <= Node.val <= 1000
The values of the nodes in the tree are unique.





class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
            return NULL;
        int l = countDepth(root->left);
        int r = countDepth(root->right);
        if(l == r)
            return root;
        else if(l < r)
            return lcaDeepestLeaves(root->right);
        else
            return lcaDeepestLeaves(root->left);
    }
    
    int countDepth(TreeNode* root){
        if(!root)
            return 0;
        if(!depth.count(root))
            depth[root] = 1 + max(countDepth(root->left), countDepth(root->right));
        return depth[root];
		
	private:
		unordered_map<TreeNode*, int> depth;
    }
};





class Solution {
public:
   int getDepth(TreeNode* root) {
    if(!root)   return 0;
    int lDepth=1+getDepth(root->left);
    int rDepth=1+getDepth(root->right);
    
    return max (lDepth, rDepth);
}

TreeNode* lcaDeepestLeaves(TreeNode* root) {
    if(!root)   return NULL;
    
    int lDepth=getDepth(root->left);
    int rDepth=getDepth(root->right);
    if(lDepth==rDepth)  return root;
    return lDepth>rDepth?lcaDeepestLeaves(root->left):lcaDeepestLeaves(root->right);
}
    
};
