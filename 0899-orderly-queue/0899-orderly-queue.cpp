class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        int i,n=s.length();
        string ans=s;
        s+=s;
        for(i=1;i<n;i++)
            ans=min(ans,s.substr(i,n));
        
        return ans;
    }
};