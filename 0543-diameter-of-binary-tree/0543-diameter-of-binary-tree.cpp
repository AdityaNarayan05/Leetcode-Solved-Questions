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
    // int diameterOfBinaryTree(TreeNode* root) {
    //     int d=0;
    //     diameter(root,d);
    //     return d;
    // }
    // int diameter(TreeNode* root,int &d){
    //     if(!root)
    //         return 0;
    //     int ld=diameter(root->left,d);
    //     int rd=diameter(root->right,d);
    //     d=max(d,ld+rd);
    //     return  max(ld,rd)+1;
    // }
    
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int leftDiam = diameterOfBinaryTree(root->left);
        int rightDiam = diameterOfBinaryTree(root->right);
        int rootDiam = maxDepth(root->left) + maxDepth(root->right);
        
        // Find max among these 3 elements
        return max({leftDiam, rightDiam, rootDiam});
    }
};