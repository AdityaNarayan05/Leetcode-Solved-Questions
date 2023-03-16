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
    TreeNode* helper(unordered_map<int,int> &m,vector<int> &postorder,int left,int right,int &pIndex){
        if(left>right) 
            return NULL;
        TreeNode* node = new TreeNode(postorder[pIndex]);
        pIndex--;
        if(left == right)
            return node;
        int inorderInd = m[node->val];
        
        node->right = helper(m,postorder,inorderInd+1,right,pIndex);
        node->left = helper(m,postorder,left,inorderInd-1,pIndex);
        
        return node;
        
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        
        unordered_map<int,int> m;
        for(int i=0;i<size;i++){
            m[inorder[i]] = i;
        }
        
        int pIndex = size-1;
        return helper(m,postorder,0,size-1,pIndex);
    }
};