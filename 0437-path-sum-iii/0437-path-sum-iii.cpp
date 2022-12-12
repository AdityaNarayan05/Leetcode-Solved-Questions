#define ll long long int

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
    
    map<ll,ll> mp;
    
    
    void solve(TreeNode *node, int targetSum, int &cnt, ll curr_sum){
        if(node == NULL) return;
        curr_sum += node->val;
        
        cnt += mp[curr_sum - targetSum];
        mp[curr_sum]++;
        
        solve(node->left,targetSum,cnt,curr_sum);
        solve(node->right,targetSum,cnt,curr_sum);
        
        mp[curr_sum]--;
        if(mp[curr_sum] == 0) mp.erase(curr_sum);
        return;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        int cnt = 0;
        ll curr_sum = 0;
        solve(root,targetSum,cnt,curr_sum);
        return cnt;
    }
};
