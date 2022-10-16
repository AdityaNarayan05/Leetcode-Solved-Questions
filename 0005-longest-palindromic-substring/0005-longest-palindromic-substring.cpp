class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int beg = 0 , siz = 1;
        vector<vector<int>> dp(n+1,vector<int> (n+1,0)) ;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(i>=j)
                    dp[i][j] = 1 ;
        
        for(int i=n-2;i>=0;i--)
            for(int j=n-1;j>i;j--){
                if(s[i]==s[j] && dp[i+1][j-1] )
                    dp[i][j] = true ;
                if(dp[i][j] && j-i+1>siz){
                    beg = i ;
                    siz = j-i+1 ;
                }
            }
        return s.substr(beg,siz) ;
    }
};