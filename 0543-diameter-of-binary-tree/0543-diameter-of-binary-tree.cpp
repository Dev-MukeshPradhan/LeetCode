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
    void helper(TreeNode* root, int &maxD){
        if(root==NULL){
            return;
        }
        int dia = levels(root->left) + levels(root->right);
        maxD=max(maxD,dia);
        helper(root->left, maxD);
        helper(root->right, maxD);

    }
    int levels(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1 + max(levels(root->left),levels(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD=0;
        helper(root,maxD);
        return maxD;
    }
};