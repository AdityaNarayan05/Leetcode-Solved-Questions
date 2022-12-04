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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            TreeNode* n=q.front();
            q.pop_front();
            TreeNode* temp=n->right;
            n->right=n->left;
            n->left=temp;
            
            if(n->left)
                q.push_back(n->left);
            if(n->right)
                q.push_back(n->right);
        }
        return root;
    }
};