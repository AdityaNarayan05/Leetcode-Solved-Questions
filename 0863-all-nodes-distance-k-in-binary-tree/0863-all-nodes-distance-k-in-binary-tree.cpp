/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // node -> parent
        unordered_map<TreeNode*, bool> vis;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) { /*First BFS to get a track of parent nodes*/
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left) {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right) {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        q.push(target);
        vis[target] = true;
        int curr_level = 0;
        
        while(!q.empty()) { /*Second BFS to go upto K level from target node and using our hashtable info*/
            int size = q.size();
            if(curr_level++ == k)
                break;
            for(int i=0; i<size; i++) {
                TreeNode* curr = q.front(); 
                q.pop();
                if(curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if(curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if(parent_track[curr] && !vis[parent_track[curr]]) {
                    q.push(parent_track[curr]);
                    vis[parent_track[curr]] = true;
                }
            }
        }
        
        vector<int> res;
        while(!q.empty()) {
            TreeNode* curr = q.front(); 
            q.pop();
            res.push_back(curr->val);
        }
        
        return res;
    }
};