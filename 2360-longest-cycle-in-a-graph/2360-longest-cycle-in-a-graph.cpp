class Solution {
public:
    int maxLength = -1;
    vector<int> vis;
    void dfs(vector<int> &edges,int si,vector<int>& store){
        if(si == -1)
            return ;
        if(vis[si]){
            int cnt = -1;
            for(int i =0;i<store.size();i++){
                if(store[i]==si){
                    cnt = i;
                    break;
                } 
            }   
            if(cnt==-1)
                return;
            int size = (store.size()-cnt);
            maxLength = max(maxLength,size);
            return ;
        }
        vis[si] = true;
        store.push_back(si);
        dfs(edges,edges[si],store);
        return ;
    }
    int longestCycle(vector<int>& edges){
        vis.resize(edges.size(),0);
        for(int i =0;i<edges.size();i++){
            if(vis[i])
                continue;
            vector<int> store;
            dfs(edges,i,store);
        }
        return maxLength;
    }
};