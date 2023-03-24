class Solution {
public:
    int dfs(vector<vector<int>> &g,vector<bool> &vis,int idx){
        auto change=0;
        vis[idx]=true;
        for(auto edge:g[idx])
            if(!vis[abs(edge)])
                change+=dfs(g,vis,abs(edge))+(edge>0);
        
        return change;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto &c:connections){
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(-c[0]);
        }
        return dfs(graph,vector<bool>(n)={},0);
    }
};