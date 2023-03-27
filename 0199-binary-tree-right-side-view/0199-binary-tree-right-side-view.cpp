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
    vector<int> res;
    void dfs(TreeNode* node,int currLvl){
        if(!node) 
            return;
        if(currLvl >= res.size()){
            cout<<node->val<<" ";
            res.push_back(node->val); 
        }
        if(node->right)
            dfs(node->right,currLvl+ 1);
        if(node->left)
            dfs(node->left,currLvl + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};