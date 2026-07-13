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
    unordered_map<int,int>mp;
public:
    void helper(TreeNode* root,int x,vector<int>&ans){
        if(!root) return;
        if(mp.find(x)==mp.end()){
            mp[x]=root->val;
            ans.push_back(root->val);
        }
        helper(root->right,x+1,ans);
        helper(root->left,x+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        helper(root,0,ans);
        return ans;
    }
};