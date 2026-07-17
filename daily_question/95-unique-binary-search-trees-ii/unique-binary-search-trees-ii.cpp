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
    vector<TreeNode*> build(int st,int end){
        vector<TreeNode*>ans;
        if(st>end) return {NULL};
        for(int i=st;i<=end;i++){
            vector<TreeNode*>left=build(st,i-1);
            vector<TreeNode*>right=build(i+1,end);
            for(auto &l:left){
                for(auto &r:right){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return build(1,n);
    }
};