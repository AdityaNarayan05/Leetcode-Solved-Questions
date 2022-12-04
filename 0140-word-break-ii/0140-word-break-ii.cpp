class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        set<string> dict(wordDict.begin(),wordDict.end());
        funct(0,s,"",ans,dict);
        return ans;
    }
    void funct(int idx,string &s,string temp,vector<string> &ans,set<string> &dict){
        if(idx==s.size()){
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        string curr="";
        for(int i=idx;i<s.size();i++){
            curr.push_back(s[i]);
            if(dict.find(curr)!=dict.end())
                funct(i+1,s,temp+curr+" ",ans,dict);
        }
    }
};