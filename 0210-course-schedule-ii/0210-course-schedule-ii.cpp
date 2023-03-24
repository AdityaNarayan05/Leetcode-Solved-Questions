class Solution {
public:
    stack<int> st; //Stack to store the Topological order
    vector<int> vis,node; // vis to store visited nodes,and "node" to store nodes in recursive stack
    bool cycle;
    map<int,vector<int>> graph;//Map to store the graph 
    
    void dfs(int n){
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfsRec(i);
    }
    
    void dfsRec(int curr){
        if(cycle)
            return;
        
        vis[curr]=true;
        node[curr]=true;
        
        for(auto i : graph[curr]){
            if(node[i])
                cycle=true;
            if(!vis[i])
                dfsRec(i);
        }
        st.push(curr);
        node[curr]=false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pR) {
        vector<int> ans;
        vis.assign(n,false);
        node.assign(n,false);
        cycle=false;
        
        for(auto i:pR)
            graph[i[1]].push_back(i[0]);
        
        dfs(n);
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        if(cycle)
            return {};
        
        return ans;
    }
};