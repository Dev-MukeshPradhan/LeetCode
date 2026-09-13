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
    TreeNode* build(vector<int>& pre, int pl, int ph, vector<int>& ino, int il, int ih){
        if(pl>ph) return NULL;
        TreeNode* root = new TreeNode(pre[pl]);
        if(pl==ph) return root;
        int i=0;
        while(i<=ih){
            if(ino[i]==pre[pl]) break;
            i++;
        }
        int leftcount = i-il;
        int rightcount = ih-i;
        root->left = build(pre, pl+1, pl+leftcount, ino, il, i-1);
        root->right = build(pre, pl+leftcount+1, ph, ino, i+1, ih);
        return root;

    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& ino) {
        int n=pre.size();
         return build(pre,0,n-1,ino,0,n-1);
        
        
    }
};