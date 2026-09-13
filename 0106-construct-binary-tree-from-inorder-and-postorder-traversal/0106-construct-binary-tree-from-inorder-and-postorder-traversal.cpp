class Solution {
public:
    TreeNode* build(vector<int>& post, int pl, int ph, vector<int>& in, int il, int ih){
        if(pl>ph) return NULL;
        TreeNode* root = new TreeNode(post[ph]);
        if(pl==ph) return root;
        int i=il;
        while(i<=ih){
            if(in[i]==post[ph]) break;
            i++;
        }
        int leftcount = i-il;
        int rightcount = ih-i;
        root->left = build(post, pl, pl+leftcount-1, in, il, i-1);
        root->right = build(post, pl+leftcount, ph-1, in, i+1, ih);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=post.size();
        return build(post,0,n-1,in,0,n-1);
        
    }
};