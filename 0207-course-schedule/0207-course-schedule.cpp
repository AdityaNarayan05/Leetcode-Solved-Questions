class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        
        for (auto val: prerequisites){
            adj[val[1]].push_back(val[0]);
        }

        vector<int> indegree(n,0);
        for (int i=0; i<n; i++){
            for (auto vl: adj[i]){
                indegree[vl]++;
            }
        }
        
        int cnt=0;
        queue<int> q;
        for (int i=0; i<n; i++){
            if (indegree[i]==0)
                q.push(i);
        }
        
        while (!q.empty()){
            int tr= q.front();
            q.pop();
            cnt++;
            for (auto val: adj[tr]){
                indegree[val]--;
                if (indegree[val]==0)
                    q.push(val);
            }
        }
        return (cnt==n);
    }
};