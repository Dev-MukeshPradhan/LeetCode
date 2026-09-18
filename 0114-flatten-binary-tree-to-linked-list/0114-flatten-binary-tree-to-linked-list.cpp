class Solution {
public:
    void pre(TreeNode* root, vector<TreeNode*> &v){
        if(root==NULL) return;
        v.push_back(root);
        pre(root->left,v);
        pre(root->right,v);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> v;
        pre(root,v);
        int n=v.size();
        for(int i=0; i<n-1; i++){
            v[i]->left=NULL;
            v[i]->right=v[i+1];
        }

        
    }
};