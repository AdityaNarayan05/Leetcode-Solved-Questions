class Solution {
public:
    int findCircleNum(vector<vector<int>>& m){
        if(m.empty())
            return 0;
        int n=m.size();
        vector<bool> vis(n,false);
        int g=0;
        for(int i=0;i<n;i++){
            g+= !vis[i] ? dfs(i,m,vis) , 1 : 0;
        }
        return g;
    }
 private:
    void dfs(int i,vector<vector<int>>& m,vector<bool>& vis){
        vis[i]=true;
        
        for(int j=0;j<vis.size();j++)
            if(i!=j&&m[i][j]&&!vis[j])
                dfs(j,m,vis);
    }
};