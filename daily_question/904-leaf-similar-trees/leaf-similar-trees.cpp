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
void leaves(TreeNode* root,vector<int>&arr){
    if(!root) return;
    if(!root->left &&!root->right) arr.push_back(root->val);
    leaves(root->left,arr);
    leaves(root->right,arr);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      vector<int>leaf1,leaf2;
      leaves(root1,leaf1);
      leaves(root2,leaf2);
      return leaf1==leaf2;
    }
};