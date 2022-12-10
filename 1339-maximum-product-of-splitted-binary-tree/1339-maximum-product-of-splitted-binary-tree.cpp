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
    long long int sum=0,totalSum=0;
    int maxProduct(TreeNode* root) {
        totalSum=dfs(root);
        dfs(root);
        return sum%int(1e9+7);
    }
    
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int currSum=dfs(root->left)+dfs(root->right)+root->val;
        sum=max(sum,(totalSum-currSum)*currSum);
        return currSum;
    }
};