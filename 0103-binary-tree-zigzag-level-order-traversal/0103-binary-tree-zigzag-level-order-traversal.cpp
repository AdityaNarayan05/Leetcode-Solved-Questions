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
    vector <vector<int>> ans;
    int count=0;
    void zigzagtraversal(TreeNode*root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector <int> arr; 
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*temp=q.front();
                q.pop();
                if(temp)
                    arr.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(count%2==0){
             if(!arr.empty())
                 ans.push_back(arr); 
            }
            else{
                reverse(arr.begin(),arr.end());
                if(!arr.empty())
                    ans.push_back(arr); 
            }
             count++;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        zigzagtraversal(root);
        return ans;
    }
};