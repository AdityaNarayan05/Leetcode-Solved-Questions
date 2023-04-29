class UnionFind{
    vector<int> parent;
public:
    UnionFind(int n) : parent(n){
        iota(begin(parent),end(parent),0);
    }
    
    int find(int v){
        if(v==parent[v])
            return v;
        return parent[v]=find(parent[v]);
    }
    void Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b)
            return;
        parent[a]=b;
    }
    
    bool connected(int a,int b){
        return (find(a)==find(b));
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& E, vector<vector<int>>& Q) {
        vector<bool> ans(Q.size());
        for(int i=0;i<Q.size();i++)
            Q[i].push_back(i);
        
        sort(begin(Q),end(Q),[&](auto& a, auto& b){
            return a[2]<b[2];
        });
        sort(begin(E),end(E),[&](auto& a, auto& b){
            return a[2]<b[2];
        });
        
        UnionFind uf(n);
        int i=0;
        
        for(auto &q: Q){
            int u=q[0],v=q[1],limit=q[2],qid=q[3];
            
            for( ;i<E.size() and E[i][2]<limit;i++)
                uf.Union(E[i][0],E[i][1]);
            
            ans[qid]=uf.connected(u,v);
        }
        return ans;
    }
};