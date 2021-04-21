Count subtrees in a BST whose nodes lie within a given range

https://www.techiedelight.com/count-subtrees-bst-whose-nodes-within-range/



#include <iostream>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return new Node(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
 
    // otherwise, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    // return root node
    return root;
}
 
// Function to count subtrees in a BST whose nodes lie within a given range.
// It returns true if the whole subtree rooted at the given node is within range
bool findSubTrees(Node* root, int low, int high, int &count)
{
    // base case
    if (root == nullptr) {
        return true;
    }
 
    // increment the subtree count by 1 and return true if the root node,
    // both left and right subtrees are within the range
    if (findSubTrees(root->left, low, high, count) &&
        findSubTrees(root->right, low, high, count) &&
        (root->data >= low && root->data <= high))
    {
        count++;
        return true;
    }
 
    return false;
}
 
int main()
{
    // input range
    int low = 5, high = 20;
 
    // BST keys to construct BST shown in the diagram
    int keys[] = { 15, 25, 20, 22, 30, 18, 10, 8, 9, 12, 6 };
 
    // construct BST
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    // get count of subtrees
    int count = 0;
    findSubTrees(root, low, high, count);
    cout << "The total number of subtrees is " << count;
 
    return 0;
}
