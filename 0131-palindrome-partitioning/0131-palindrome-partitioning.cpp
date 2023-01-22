class Solution {
public:
    bool isPalin(string s,int start,int end){
        while(start<end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(int idx,string s,vector<vector<string>>& ans,vector<string> ds){
        if(idx==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<s.size();++i){
            if(isPalin(s,idx,i)){
                ds.push_back(s.substr(idx,i-idx+1));
                solve(i+1,s,ans,ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0,s,ans,ds);
        return ans;
    }
};