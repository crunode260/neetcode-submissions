/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
bool isBalanced(TreeNode* root){
  bool stillValid = true;
  height(root, stillValid);
  return stillValid;
}

int height(TreeNode* node, bool &stillValid){ 
  if (!stillValid){
    return 0;
  }
  if (!node){
    return -1;
  }
  int lHeight = height(node->left, stillValid);
  int rHeight = height(node->right, stillValid);
  if (abs(lHeight - rHeight) > 1){
    stillValid = false;
    return 0;
  }
  return (max(lHeight, rHeight) + 1);
}
};
