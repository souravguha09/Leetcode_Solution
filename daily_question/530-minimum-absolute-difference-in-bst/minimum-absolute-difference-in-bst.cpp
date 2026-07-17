class Solution {
public:
    TreeNode* prev = nullptr;
    int diff = INT_MAX;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev)
            diff = min(diff, root->val - prev->val);

        prev = root;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return diff;
    }
};