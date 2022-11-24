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
    int maxPathSumUtil(TreeNode *root,int &ans){
        if(root==NULL)
            return 0;
        
        int l=maxPathSumUtil(root->left,ans);
        int r=maxPathSumUtil(root->right,ans);
        
        int nodeMax=max(max(root->val,root->val+l+r),max(root->val+l,root->val+r));
        ans=max(ans,nodeMax);
        
        int sps=max(root->val,max(root->val+l,root->val+r));
        return sps;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxPathSumUtil(root,ans);
        return ans;
    }
};