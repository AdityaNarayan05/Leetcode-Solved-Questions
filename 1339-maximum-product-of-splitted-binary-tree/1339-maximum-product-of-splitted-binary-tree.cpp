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
    int m=1e9+7;
    unordered_map<long long int,long long int>mp;
    long long  int sum(TreeNode * root){
        if(!root)
            return 0;
        int left=sum(root->left);
        mp[left]++;
        int right=sum(root->right);
        mp[right]++;
        return left + right+root->val;
    }
    int maxProduct(TreeNode* root) {
        long long  int total=  sum(root);
        cout<<total<<endl;
        long long    int ans=INT_MIN;
        for(auto it : mp)
            ans=max(ans,it.first*(total-it.first));
        
        return ans%m;
    }
};