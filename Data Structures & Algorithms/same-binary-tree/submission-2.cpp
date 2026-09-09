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
bool isSameTree(TreeNode* p, TreeNode* q){
  stack<TreeNode*> pStack;
  stack<TreeNode*> qStack;

  if (!p){
    if (!q){
      return true;
    }
    return false;
  }
  if (!q){
    return false;
  }

  pStack.push(p);
  qStack.push(q);
  TreeNode* curP = p;
  TreeNode* curQ = q;
  while (!pStack.empty()){
    if (qStack.empty()){
      return false;
    }
    if (!curQ){
      if (curP){
        return false;
      }
    }
    if (!curP){
      if (curQ){
        return false;
      }
      curP = pStack.top()->right;
      curQ = qStack.top()->right;
      pStack.pop();
      qStack.pop();
    }
    else{
      if (curP->val != curQ->val){
        return false;
      }
      pStack.push(curP);
      qStack.push(curQ);
      curP = curP->left;
      curQ = curQ->left;
    }
    
  }
  if (!qStack.empty()){
    return false;
  }
  return true;
}
};
