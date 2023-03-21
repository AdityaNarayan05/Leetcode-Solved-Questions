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
    void kthsmall(TreeNode* root,int k,int* count,int* element){
        if(!root)
            return;
        if(root->left)
            kthsmall(root->left,k,count,element);
        (*count)++;
        if(k==*count)
            *element=root->val;
        if(root->right)
            kthsmall(root->right,k,count,element);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int element=-1;
        kthsmall(root,k,&count,&element);
        return element;
    }
};