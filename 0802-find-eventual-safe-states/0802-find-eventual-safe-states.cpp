class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &dp, int src) {
        if(dp[src])
            return 1 == dp[src];
        
        dp[src] = -1; // by default mark it as "cannnot be topologically sorted"
        for(auto node : graph[src])
            if(!dfs(graph, dp,node))
                return false;
        
        return dp[src] = 1; // next node with zero outdegree
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result, dp(n,0);
        for(int i = 0; i < n; i++)
            if(dfs(graph, dp, i))
                result.push_back(i);
        
        return result;
    }  
};