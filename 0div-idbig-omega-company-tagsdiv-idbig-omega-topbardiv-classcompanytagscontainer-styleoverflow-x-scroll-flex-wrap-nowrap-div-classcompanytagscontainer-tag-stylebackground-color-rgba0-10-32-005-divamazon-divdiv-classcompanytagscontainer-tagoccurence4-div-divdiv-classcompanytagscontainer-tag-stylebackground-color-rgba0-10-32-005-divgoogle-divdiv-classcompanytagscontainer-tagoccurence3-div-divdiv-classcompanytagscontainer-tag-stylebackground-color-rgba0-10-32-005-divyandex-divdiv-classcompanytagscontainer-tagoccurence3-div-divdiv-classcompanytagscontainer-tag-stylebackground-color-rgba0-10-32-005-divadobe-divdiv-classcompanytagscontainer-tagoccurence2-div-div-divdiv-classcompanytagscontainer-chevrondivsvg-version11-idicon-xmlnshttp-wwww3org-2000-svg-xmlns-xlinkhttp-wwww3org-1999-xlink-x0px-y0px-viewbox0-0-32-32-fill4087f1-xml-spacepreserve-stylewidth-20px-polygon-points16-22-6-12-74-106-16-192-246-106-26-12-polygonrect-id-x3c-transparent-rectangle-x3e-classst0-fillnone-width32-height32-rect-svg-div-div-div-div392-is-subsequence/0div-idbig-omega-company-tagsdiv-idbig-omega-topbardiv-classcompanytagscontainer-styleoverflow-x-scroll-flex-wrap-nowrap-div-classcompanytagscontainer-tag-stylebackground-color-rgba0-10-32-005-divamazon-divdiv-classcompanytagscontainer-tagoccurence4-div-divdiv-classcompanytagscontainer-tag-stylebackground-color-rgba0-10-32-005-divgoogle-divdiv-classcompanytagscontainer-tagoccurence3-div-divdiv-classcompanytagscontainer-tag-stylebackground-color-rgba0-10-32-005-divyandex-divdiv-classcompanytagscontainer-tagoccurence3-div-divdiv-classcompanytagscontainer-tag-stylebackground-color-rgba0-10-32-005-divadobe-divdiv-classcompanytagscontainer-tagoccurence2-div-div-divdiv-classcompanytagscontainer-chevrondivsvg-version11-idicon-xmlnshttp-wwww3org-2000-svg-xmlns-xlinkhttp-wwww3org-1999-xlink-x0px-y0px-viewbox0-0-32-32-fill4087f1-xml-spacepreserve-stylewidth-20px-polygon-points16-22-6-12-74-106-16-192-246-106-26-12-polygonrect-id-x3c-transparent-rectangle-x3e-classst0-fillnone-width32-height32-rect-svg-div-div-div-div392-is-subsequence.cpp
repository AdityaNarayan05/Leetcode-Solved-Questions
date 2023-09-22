class Solution {
public:
    bool isSubsequence(string s, string t) {
        return comp(s,s.size(),t,t.size());
    }
    bool comp(string &s,int m,string &t,int n){
        if(m==0)
            return true;
        if(n==0)
            return false;
        
        if(s[m-1]==t[n-1])
            return comp(s,m-1,t,n-1);
        
        return comp(s,m,t,n-1);
    }
};