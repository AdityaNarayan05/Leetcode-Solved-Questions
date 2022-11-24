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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        getPathSum(root, ans);
        return ans;
    }

    int getPathSum(TreeNode* node, int& ans) {
        if (!node)
            return 0;

        int lvalue = max(getPathSum(node->left, ans), 0);
        int rvalue = max(getPathSum(node->right, ans), 0);
        ans = max(ans, node->val + lvalue + rvalue);
        return node->val + max(lvalue, rvalue);
    }
};