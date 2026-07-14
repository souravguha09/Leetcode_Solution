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
TreeNode*  parentTrack(TreeNode* root,int start,unordered_map<TreeNode*,TreeNode*>&mp){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
            TreeNode* node=q.front();
            if(node->val==start) res=node;
            q.pop();
            if(node->left){
            mp[node->left]=node;
            q.push(node->left);
            }
            if(node->right){
            mp[node->right]=node;
            q.push(node->right);
            }
            }
        }
     return res;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>mp;
        TreeNode* tar=parentTrack(root,start,mp);
        int time=0;
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        q.push(tar);
        vis[tar]=true;
        while(!q.empty()){
          bool f=false;
          int n=q.size();
          for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                q.push(node->left);
                vis[node->left]=true;
                f=true;
            }
            if(node->right && !vis[node->right]){
                q.push(node->right);
                vis[node->right]=true;
                f=true;
            }
            if(mp[node] && !vis[mp[node]]){
                q.push(mp[node]);
                vis[mp[node]]=true;
                f=true;
            }
          }
          if(f) time++;
        }
        return time;
    }
};