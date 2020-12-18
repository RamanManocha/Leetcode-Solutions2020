AVL Trees & Rotations
An AVL Tree is a self-balancing binary search tree.

Given an array of integers items and a threshold threshold, return the tree resulting from performing insertions of each element items[i] while maintaining the AVL balance property with threshold threshold.

Example 1:
Input:
items = [1,2,3]
threshold = 1

Output:
          2
        /   \
       1     3

Explanation:
        1
         \
          2
           \
            3

Do a Left Rotation
Left Rotation (Rooted On 1):

          2
        /   \
       1     3

Example 2:
Input:
items = [3, 1, 2]
threshold = 1

Output:
          2
        /   \
       1     3

Explanation:
        3
       /
      1
       \
        2

Do a Left-Right Rotation
Left Rotation (Rooted On 1):

        3
       /
      2
     /
    1

Right Rotation (Rooted On 3):

          2
        /   \
       1     3
       
       
       
       
       
       
       
       
       
       
       
   const insertAVL = (items, threshold) => {
  if (!items || items.length === 0) {
    return null;
  }

  let root = new AVLNode(items[0]);

  for (let idx = 1; idx < items.length; idx++) {
    root = insert(root, items[idx], threshold);
  }

  return convertAvlNodesToTreenode(root);
}

const insert = (node, key, threshold) => {
  if (!node) {
    return new AVLNode(key);
  }

  if (key < node.val) {
    node.left = insert(node.left, key, threshold);
  } else {
    node.right = insert(node.right, key, threshold);
  }

  node.height = 1 + Math.max(
    getHeight(node.left),
    getHeight(node.right)
  );
  const balance = getBalance(node);

  if (balance > threshold) {
    if (getBalance(node.left) >= 0) {
      node = rotateRight(node);
    } else {
      node = rotateLeftRight(node);
    }
  } else if (balance < -threshold) {
    if (getBalance(node.right) <= 0) {
      node = rotateLeft(node);
    } else {
      node = rotateRightLeft(node);
    }
  }

  return node;
}

const rotateRight = (node) => {
  const leftTemp = node.left;

  node.left = leftTemp.right;
  leftTemp.right = node;

  node.height = 1 + Math.max(
    getHeight(node.left),
    getHeight(node.right)
  );
  leftTemp.height = 1 + Math.max(
    getHeight(leftTemp.left),
    getHeight(leftTemp.right)
  );

  return leftTemp;
}

const rotateLeft = (node) => {
  const rightTemp = node.right;

  node.right = rightTemp.left;
  rightTemp.left = node;

  node.height = 1 + Math.max(
    getHeight(node.left),
    getHeight(node.right)
  );
  rightTemp.height = 1 + Math.max(
    getHeight(rightTemp.left),
    getHeight(rightTemp.right)
  );

  return rightTemp;
}

const rotateLeftRight = (node) => {
  node.left = rotateLeft(node.left);

  return rotateRight(node);
}

const rotateRightLeft = (node) => {
  node.right = rotateRight(node.right);

  return rotateLeft(node);
}

const getBalance = (node) => {
  if (!node) {
    return 0;
  }

  return getHeight(node.left) - getHeight(node.right);
}

const getHeight = (node) => {
  if (!node) {
    return -1;
  }

  return node.height;
}

const convertAvlNodesToTreenode = (avlNode) => {
  if (!avlNode) {
    return null;
  }

  const root = new TreeNode(avlNode.val);

  root.left = convertAvlNodesToTreenode(avlNode.left);
  root.right = convertAvlNodesToTreenode(avlNode.right);

  return root;
}

class AVLNode {
  constructor(val) {
    this.val = val;
    this.height = 0;
    this.left = null;
    this.right = null;
  }
}    
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       This is in C#
       
   public class Solution
{
  public TreeNode insertAVL(int[] items, int threshold)
  {
    if (items == null || items.Length == 0)
    {
      return null;
    }

    AVLNode root = new AVLNode(items[0]);

    for (int idx = 1; idx < items.Length; idx++)
    {
      root = Insert(root, items[idx], threshold);
    }

    return ConvertAvlNodesToTreenode(root);
  }

  private AVLNode Insert(AVLNode node, int key, int threshold)
  {
    if (node == null)
    {
      return new AVLNode(key);
    }

    if (key < node.Val)
    {
      node.Left = Insert(node.Left, key, threshold);
    }
    else
    {
      node.Right = Insert(node.Right, key, threshold);
    }

    node.Height = 1 + Math.Max(
      GetHeight(node.Left),
      GetHeight(node.Right)
    );
    int balance = GetBalance(node);

    if (balance > threshold)
    {
      if (GetBalance(node.Left) >= 0)
      {
        node = RotateRight(node);
      }
      else
      {
        node = RotateLeftRight(node);
      }
    }
    else if (balance < -threshold)
    {
      if (GetBalance(node.Right) <= 0)
      {
        node = RotateLeft(node);
      }
      else
      {
        node = RotateRightLeft(node);
      }
    }

    return node;
  }

  private AVLNode RotateRight(AVLNode node)
  {
    AVLNode leftTemp = node.Left;

    node.Left = leftTemp.Right;
    leftTemp.Right = node;

    node.Height = 1 + Math.Max(
      GetHeight(node.Left),
      GetHeight(node.Right)
    );
    leftTemp.Height = 1 + Math.Max(
      GetHeight(leftTemp.Left),
      GetHeight(leftTemp.Right)
    );

    return leftTemp;
  }

  private AVLNode RotateLeft(AVLNode node)
  {
    AVLNode rightTemp = node.Right;

    node.Right = rightTemp.Left;
    rightTemp.Left = node;

    node.Height = 1 + Math.Max(
      GetHeight(node.Left),
      GetHeight(node.Right)
    );
    rightTemp.Height = 1 + Math.Max(
      GetHeight(rightTemp.Left),
      GetHeight(rightTemp.Right)
    );

    return rightTemp;
  }

  private AVLNode RotateLeftRight(AVLNode node)
  {
    node.Left = RotateLeft(node.Left);

    return RotateRight(node);
  }

  private AVLNode RotateRightLeft(AVLNode node)
  {
    node.Right = RotateRight(node.Right);

    return RotateLeft(node);
  }

  private int GetBalance(AVLNode node)
  {
    if (node == null)
    {
      return 0;
    }

    return GetHeight(node.Left) - GetHeight(node.Right);
  }

  private int GetHeight(AVLNode node)
  {
    if (node == null)
    {
      return -1;
    }

    return node.Height;
  }

  private TreeNode ConvertAvlNodesToTreenode(AVLNode avlNode)
  {
    if (avlNode == null)
    {
      return null;
    }

    TreeNode root = new TreeNode(avlNode.Val);

    root.Left = ConvertAvlNodesToTreenode(avlNode.Left);
    root.Right = ConvertAvlNodesToTreenode(avlNode.Right);

    return root;
  }
}

class AVLNode
{
  public int Val;
  public int Height;
  public AVLNode Left, Right;

  public AVLNode(int val)
  {
    this.Val = val;
    this.Height = 0;
    this.Left = null;
    this.Right = null;
  }
}    
       
       
       
       
       
       
       
       
       
  
