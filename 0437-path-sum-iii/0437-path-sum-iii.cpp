class Solution {
public:
    void helper(TreeNode* root, int &count, long long targetSum){
        if(root==NULL) return;
        if(targetSum==(long long)root->val) count++;
        helper(root->left,count,targetSum-(long long)(root->val));
        helper(root->right,count,targetSum-(long long)(root->val));

    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int count=0;
        helper(root,count,(long long)targetSum);
        count += (pathSum(root->left,targetSum) + pathSum(root->right,targetSum));
        return count;
        
        
    }
};