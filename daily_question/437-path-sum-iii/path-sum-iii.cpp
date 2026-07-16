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
    void dfs(TreeNode* root,long long sum,long long tar,int &cnt){
        if(!root) return ;
        sum+=root->val;
        if(sum==tar) cnt++;
        dfs(root->left,sum,tar,cnt);
        dfs(root->right,sum,tar,cnt);
    }
    int pathSum(TreeNode* root, int target) {
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            dfs(node,0,target,cnt);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return cnt;
    }
};