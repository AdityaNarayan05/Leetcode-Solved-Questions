class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res=0;
        for(int i=0;i<n;++i){
            res=max(res,dfs(i,manager,informTime));
        }
        return res;
    }
    int dfs(int i,vector<int>& m,vector<int>& iT){
        if(m[i]!=-1){
            iT[i]+=dfs(m[i],m,iT);
            m[i]=-1;
        }
        return iT[i];
    }
};