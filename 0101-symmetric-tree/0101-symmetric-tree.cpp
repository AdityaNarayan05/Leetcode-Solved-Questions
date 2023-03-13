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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true; //Tree is empty
        
        return comp(root->left,root->right);
    }
    
    bool comp(TreeNode* p , TreeNode* q){
        if(!p && !q) //left & right node is NULL 
            return true; 
        
        else if(!p || !q) //one of them is Not NULL
            return false; 
        
        else if(p->val != q->val) 
            return false;
        
        return comp(p->left,q->right) && comp(p->right,q->left); 
    }  
};