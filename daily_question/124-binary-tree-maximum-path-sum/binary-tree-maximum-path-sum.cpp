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
    int f(TreeNode* root,int &sum){
        if(!root) return 0;
        int leftsum=f(root->left,sum);
        int rightsum=f(root->right,sum);
        int total=leftsum+rightsum+root->val;
        sum=max({sum,total,leftsum+root->val,rightsum+root->val,root->val});
        return max({root->val,root->val+leftsum,root->val+rightsum});
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int sum=INT_MIN;
        f(root,sum);
        return sum;

    }
};