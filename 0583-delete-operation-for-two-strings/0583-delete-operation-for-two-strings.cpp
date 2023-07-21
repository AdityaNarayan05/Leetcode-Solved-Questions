class Solution {
public:
    vector<vector<int>> dp;
    int lcs(int i1,int i2,string &s1,string &s2){
        if(i1>=s1.size() or i2>=s2.size())
            return 0;
        
        if(dp[i1][i2]!=-1)
            return dp[i1][i2];
        
        if(s1[i1]==s2[i2])
            return dp[i1][i2]=1+lcs(i1+1,i2+1,s1,s2);
        else
            return dp[i1][i2]=0+ max(lcs(i1+1,i2,s1,s2),lcs(i1,i2+1,s1,s2));
    }
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        dp.resize(n,vector<int>(m,-1));
        int k=lcs(0,0,s1,s2);
        
        return n+m-2*k;
    }
};