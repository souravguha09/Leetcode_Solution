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
    TreeNode* helper(TreeNode* root,int sum,int lim){
        if(!root) return NULL;
        sum+=root->val;
        if(!root->left && !root->right){
            if(sum<lim) return nullptr;
            return root;
        }
       root->left= helper(root->left,sum,lim);
       root->right=helper(root->right,sum,lim);  
       if(!root->left && !root->right) return nullptr;
       return root;
    }
    
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
       return helper(root,0,limit);
    }
};