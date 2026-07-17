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
    TreeNode* prev=NULL;
public:
    void dfs(TreeNode* root){
           if(!root) return;
           dfs(root->right);
           root->right=prev;
           prev=root;
           dfs(root->left);
           root->left=NULL;

    }
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        return prev;
    }
};