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
    int findSecondMinimumValue(TreeNode* root) {
        long long mn=root->val;
        long long smn=LLONG_MAX;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            if(node->val<mn){
                smn=mn;
                mn=node->val;
            }
            else if(node->val>mn && node->val<smn) smn=node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }
        return smn==LLONG_MAX?-1:smn;
    }
};