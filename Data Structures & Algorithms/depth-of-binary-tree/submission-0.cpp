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
    int maxDepth(TreeNode* root) {
        stack<TreeNode*> nodes;
        TreeNode* currentNode = root;
        stack<int> depths;
        int maxDepth = 0;
        if (!root){
            return 0;
        }
        nodes.push(root);
        depths.push(1);
        int depth = 1;
        while (!nodes.empty()){
            if (!currentNode){
            currentNode = nodes.top()->right;
            nodes.pop();
            depth = depths.top() + 1;
            depths.pop();
            }
            else{
            if (depth > maxDepth){
                maxDepth = depth;
            }
            nodes.push(currentNode);
            depths.push(depth);
            currentNode = currentNode->left;
            depth++;
            }
        }
        return maxDepth;

                
    }
};
