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
    // void helper(TreeNode* root, vector<int> &ans){
    //     if(root==NULL) return;
    //     helper(root->left,ans);
    //     ans.push_back(root->val);
    //     helper(root->right,ans);

    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*> st;
        TreeNode* it_node = root;
        while(st.size()>0 || it_node!=NULL){
            if(it_node){
                st.push(it_node);
                it_node=it_node->left;
            }else{
                TreeNode* temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                it_node=temp->right;

            } 
        }
        return ans;
        
    }
};