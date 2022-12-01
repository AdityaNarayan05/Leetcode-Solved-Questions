class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<char>> dp(s.size()+1,vector<char>(p.size()+1,-1));
        return isMatch(0,s,0,p,dp);    
    }
    bool isMatch(int i, string& s, int j, string &p, vector<vector<char>> &dp) {
        if(dp[i][j] > -1) return dp[i][j];
        int pn=p.size(), sn = s.size();
        if(j==pn) return dp[i][j] = i==sn;
        if(p[j+1]=='*') {
            if(isMatch(i,s,j+2,p,dp) || 
               i<sn && (p[j] == '.' || s[i] == p[j]) && isMatch(i+1,s,j,p,dp)) 
			   return dp[i][j] = 1;
        } else if (i<sn && (p[j]=='.'|| s[i]==p[j]) && isMatch(i+1,s,j+1,p,dp)) 
			return dp[i][j] = 1;
        return dp[i][j] = 0;
    }
};