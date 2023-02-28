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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*>> mp;
        vector<TreeNode*> dups;
        dfs(root,mp);
        for(auto it=mp.begin();it!=mp.end();it++)
            if(it->second.size() > 1)
                dups.push_back(it->second[0]);
        
        return dups;
    }
    string dfs(TreeNode* node,unordered_map<string,vector<TreeNode*>> &mp){
        if(!node)
            return "";
        string s="("+dfs(node->left,mp)+to_string(node->val)+dfs(node->right,mp)+")";
        mp[s].push_back(node);
        return s;
    }
};