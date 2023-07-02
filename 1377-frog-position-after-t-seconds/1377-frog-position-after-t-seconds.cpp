class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    int target;
    long double prob=0;
    
    bool dfs(int node,int t,long double p){
        if(t<0)
            return false;
        
        vis[node]=true;
        if(node==target){
            if(t==0 or adj[node].size()==(node!=1))
                this->prob=p;
            return true;
        }
        
        for(auto n:adj[node]){
            if(!vis[n] and dfs(n,t-1, p*(long double)1/(adj[node].size() - (node!=1))))
                return true;
        }
        return false;
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        adj.resize(n+1);
        vis.resize(n+1);
        this->target=target;
        
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        dfs(1,t,1);
        
        return prob;
    }
};