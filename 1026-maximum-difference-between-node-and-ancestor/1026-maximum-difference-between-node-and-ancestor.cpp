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
    int maxAncestorDiff(TreeNode* root, int ancestor_min=100000, int ancestor_max=0) {
        if (root) 
            return max(maxAncestorDiff(root->left, min(root->val, ancestor_min), max(root->val, ancestor_max)),
                   maxAncestorDiff(root->right, min(root->val, ancestor_min), max(root->val, ancestor_max)));
        else 
            return ancestor_max - ancestor_min;
    }
};