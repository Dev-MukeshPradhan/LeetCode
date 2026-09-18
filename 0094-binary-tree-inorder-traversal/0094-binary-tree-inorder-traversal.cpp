class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        TreeNode* curr = root;

        while (curr != NULL) {

            if (curr->left != NULL) {

                // Find inorder predecessor
                TreeNode* pred = curr->left;

                while (pred->right != NULL && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == NULL) {

                    // Create temporary link
                    pred->right = curr;

                    // Move to left subtree
                    curr = curr->left;

                } 
                else {

                    // Remove temporary link
                    pred->right = NULL;

                    // Visit current node
                    ans.push_back(curr->val);

                    // Move to right subtree
                    curr = curr->right;
                }

            } 
            else {

                // No left subtree → visit immediately
                ans.push_back(curr->val);

                // Move right
                curr = curr->right;
            }
        }

        return ans;
    }
};