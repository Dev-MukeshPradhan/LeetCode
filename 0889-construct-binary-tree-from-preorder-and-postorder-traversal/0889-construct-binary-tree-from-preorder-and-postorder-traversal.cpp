class Solution {
public:
    TreeNode* build(vector<int>& pre, int prelo, int prehi, vector<int>& post, int postlo, int posthi){
        if(prelo>prehi) return NULL;
        TreeNode* root = new TreeNode(pre[prelo]);
        if(prelo==prehi) return root;
        //int leftroot = pre[prelo+1];
        int i=postlo;
        while(i<posthi){
            if(post[i]==pre[prelo+1]) break;
            i++;
        }
        int leftcount = i-postlo+1;
        root->left = build(pre, prelo+1, prelo+leftcount, post, postlo, i);
        root->right = build(pre, prelo+leftcount+1, prehi, post, i+1, posthi-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n=pre.size();
        return build(pre, 0, n-1, post, 0, n-1);
        
    }
};