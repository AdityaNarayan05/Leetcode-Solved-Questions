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
    vector<int> arr;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        cout<<root->val<<" ";
        arr.push_back(root->val);
        inorder(root->right);
    }
    int bs(int num){
        int l = 0, r = arr.size() - 1;
        int mid;
        
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (arr[mid] < num) {
                l = mid + 1;
            } else {
                r = mid;
            }
        } 
        if (arr[l] == num) {
        // cout << "Found"
        //      << " At Index " << l << endl;
            return l;
        } else if (arr[r] == num) {
        // cout << "Found"
        //      << " At Index " << r << endl;
            return r;
        }
        return 0;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root);
        int l=bs(low);
        int r=bs(high);
        int ans=0;
        for(int i=l;i<=r;i++){
            ans+=arr[i];
        }
        return ans;
        return 0;
    }
};