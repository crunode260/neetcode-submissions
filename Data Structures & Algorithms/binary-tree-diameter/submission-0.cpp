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
int diameterOfBinaryTree(TreeNode* root){
  TreeNode* heightRoot = height(root);
  queue<TreeNode*> nodes;
  nodes.push(heightRoot);
  TreeNode* currentNode = heightRoot;
  int maxDiameter = 0;
  int diameter;
  while (!nodes.empty()){
    if (currentNode->val == -1){
      currentNode = nodes.front();
      nodes.pop();
    }
    else{
      diameter = currentNode->left->val + currentNode->right->val + 2;
      if (diameter > maxDiameter){
        maxDiameter = diameter;
      }
      nodes.push(currentNode->left);
      nodes.push(currentNode->right);
      currentNode = nodes.front();
      nodes.pop();
    }
  }
  return maxDiameter;

}

TreeNode* height(TreeNode* node){
  if (!node){
    TreeNode* nullNode = new TreeNode();
    nullNode->val = -1;
    nullNode->left = nullptr;
    nullNode->right = nullptr;
    return nullNode;
  }
  else{
    TreeNode* leftHeight = height(node->left);
    TreeNode* rightHeight = height(node->right);
    TreeNode* currentHeight = new TreeNode();
    currentHeight->val = max(leftHeight->val, rightHeight->val) + 1;
    currentHeight->left = leftHeight;
    currentHeight->right = rightHeight;
    return currentHeight;
  }
}
};
