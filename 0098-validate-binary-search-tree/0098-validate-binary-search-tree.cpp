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
    bool ValidBST(TreeNode* root,long minval,long maxval) {
         if(!root)
             return true;
         
         if(root->val>=maxval or root->val<=minval )
             return false;
        bool l=  ValidBST( root->left,minval,root->val);
        bool r=  ValidBST( root->right,root->val,maxval);
        return l&&r;
    }
    bool isValidBST( TreeNode*root){
        return ValidBST(root,LONG_MIN,LONG_MAX);
    }
};