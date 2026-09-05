class Solution {
public:

    bool helper(TreeNode* left, TreeNode* right) {

        // Both nodes are NULL → symmetric
        if(left == NULL && right == NULL)
            return true;

        // One is NULL, other isn't → not symmetric
        if(left == NULL || right == NULL)
            return false;

        // Values are different → not symmetric
        if(left->val != right->val)
            return false;

        // Check mirror positions
        return helper(left->left, right->right) &&
               helper(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return true;

        return helper(root->left, root->right);
    }
};