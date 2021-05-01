
https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/

https://www.youtube.com/watch?v=ZdIrKO7gqok&ab_channel=CodeLibrary


unordered_map<Node, int> dp;

int func(Node root){

if(!root) return 0;

if(dp[root]) return dp[root]; 

int inc =  root->data;

if(root->left){

inc+=  func(root->left->left); inc += func(root->left-right);

if(root->right) {

inc func(root->right->left); inc + func(root->right->right);

int exc =  func(root->left) + func(root->right);

dp[root]=  max(inc, exc);

return dp[root];
}
