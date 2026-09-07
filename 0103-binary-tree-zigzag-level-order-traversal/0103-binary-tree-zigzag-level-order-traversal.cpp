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
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void nthLevel(TreeNode* root, int curL, int Level, vector<int>&ans){
        if(root==NULL) return;
        if(curL==Level){
            ans.push_back(root->val);
            return;
        }
        if(Level%2!=0){
            nthLevel(root->left,curL+1,Level,ans);
            nthLevel(root->right,curL+1,Level,ans);
        }else{
            nthLevel(root->right,curL+1,Level,ans);
            nthLevel(root->left,curL+1,Level,ans);
        
        }
        


    }
    vector<vector<int>> helper(TreeNode* root){
        int n = levels(root);
        vector<vector<int>> finalAns;
        for(int i=1; i<=n; i++){
            vector<int>ans;
            nthLevel(root,1,i,ans);
            finalAns.push_back(ans);
        }
        return finalAns;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return helper(root);
        
    }
};