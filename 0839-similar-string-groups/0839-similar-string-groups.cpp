class Solution {
public:
    vector<bool> vis;
    
    bool isSim(string a,string b){
        int cnt=0;
        for(int i=0;i<a.size();i++)
            if(a[i]!=b[i])
                cnt++;
        
        return (cnt==2 or cnt==0);
    }
    
    void dfs(int i,vector<string> &s){
        vis[i]=true;
        for(int j=0;j<s.size();j++){
            if(vis[j])
                continue;
            if(isSim(s[i],s[j]))
                dfs(j,s);
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int groups=0,n=strs.size();
        vis.resize(n,false);
        for(int i=0;i<strs.size();i++){
            if(vis[i])
                continue;
            groups++;
            dfs(i,strs);
        }
        return groups;
    }
};