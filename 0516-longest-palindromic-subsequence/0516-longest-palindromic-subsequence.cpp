class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        return lps(s,0,n-1,dp);
    }
    int lps(string &s,int l,int r,vector<vector<int>> &dp){
        if(l==r)
            return 1;
        if(l>r)
            return 0;
        if(dp[l][r])
            return dp[l][r];
        
        dp[l][r] = s[l]==s[r] ? 2+lps(s,l+1,r-1,dp):max(lps(s,l+1,r,dp),lps(s,l,r-1,dp));
        return dp[l][r];
    }
};