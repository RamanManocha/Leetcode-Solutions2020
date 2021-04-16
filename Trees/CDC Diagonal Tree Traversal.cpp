


Diagonal Tree Traversal
Given a binary tree root, return the sum of each of the diagonals in the tree starting from the top to bottom right.

Constraints

n ≤ 100,000 where n is the number of nodes in root
Example 1
Input
Visualize
root =
1

4

2

5

3

7

6

Output
[6, 15, 7]
Explanation
The diagonals are:

1 -> 2 -> 3
4 -> 5 -> 6
7
Example 2
Input
Visualize
root =
1

2

3

Output
[4, 2]







vector<int> res;
map<int, int> x0y;

void travel(Tree* root, int x, int y) {
    if (!root) return;

    int i = 0;
    int j = y - x;

    x0y[j] += root->val;

    if (root->left) travel(root->left, x - 1, y + 1);

    if (root->right) travel(root->right, x + 1, y + 1);
}

vector<int> solve(Tree* root) {
    // store the nodes in a matrix?
    // let the first node be ?
    travel(root, 0, 0);

    res;

    for (auto& a : x0y) {
        res.emplace_back(a.second);
    }

    return res;
}
