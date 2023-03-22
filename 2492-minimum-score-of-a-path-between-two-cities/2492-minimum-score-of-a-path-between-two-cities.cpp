class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans=INT_MAX;
        vector<vector<pair<int,int>>> g(n+1);
        for(auto e:roads){
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        
        vector<int> vis(n+1,0);
        queue<int> q;
        q.push(1);
        vis[1]=1;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto &[v,dis]:g[node]){
                ans=min(ans,dis);
                if(vis[v]==0){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};