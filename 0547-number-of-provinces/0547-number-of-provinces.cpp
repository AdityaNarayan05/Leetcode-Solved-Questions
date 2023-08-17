class Solution {
public:
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj){
        vis[node]=1;
        
        for(auto x: adj[node]){
            if(!vis[x]){
                dfs(x,vis,adj);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(isConnected.size());
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){   
                cnt++;
                dfs(i,vis,adj);
            }
        }
        
        return cnt;
    }
};