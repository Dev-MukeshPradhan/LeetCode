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
    TreeNode* inPred(TreeNode* root){
        // No need for base case beacause we have already seen both the nodes are existing
        // here we do not need to check for NULL
        TreeNode* pred = root->left;
        while(pred->right!=NULL){
            pred = pred->right;
        }
        return pred;
    }
    TreeNode* inSuc(TreeNode* root){
        // No need for base case beacause we have already seen both the nodes are existing
        // here we do not need to check for NULL
        TreeNode* suc = root->right;
        while(root->left!=NULL){
            suc = suc->left;
        }
        return suc;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            // case 1 : leaf node
            if(root->left==NULL && root->right==NULL){
                return NULL;
            }

            // case 2 : node with one child
            if(root->left==NULL || root->right==NULL){
                if(root->left==NULL){
                    return root->right;
                }else{
                    return root->left;
                }
            }

            // case 3 : root with both left and right child
            if(root->left!=NULL && root->right!=NULL){
                // replace the key root with inorder predecessor/successor
                TreeNode* pred = inPred(root);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            }
        }
        else if(key < root->val){
            root->left=deleteNode(root->left,key);
        }else{
            root->right=deleteNode(root->right,key);
        }
        return root;
        
    }
};