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
    void valid(TreeNode* root, TreeNode* &prev, bool &flag){
        if(root==NULL) return;
        valid(root->left,prev,flag);
        if(prev!=NULL){
            if(root->val <= prev->val){
                flag = false;
                return;
            }
            
        }
        prev=root;
        valid(root->right,prev,flag);
    }
    bool isValidBST(TreeNode* root) {
        bool flag=true;
        TreeNode* prev = NULL;
        valid(root, prev, flag);
        return flag;
        
    }
};