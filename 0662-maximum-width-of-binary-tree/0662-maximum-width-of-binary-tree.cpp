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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        queue<pair<TreeNode* , long long>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int sizz=q.size();
            int minn=q.front().second;
            int ft,lt;
            for(int i=0; i<sizz; i++)
            {
                long long curr_id=q.front().second-minn;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) ft=curr_id;
                if(i==sizz-1) lt=curr_id;
                if(node->left) q.push({node->left,curr_id*2+1});
                if(node->right) q.push({node->right,curr_id*2+2});
                
            }
            ans=max(ans,lt-ft+1);
        }
        return ans;
    }
};