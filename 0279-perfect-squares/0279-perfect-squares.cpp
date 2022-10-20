class Solution {
public:
    
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int j=1;j<=n;j++){
            int ans=INT_MAX;
            for(int i=1;i*i<=j;i++)
                ans=min(ans,1+dp[j-i*i]);
            
            dp[j]=ans;
        }
        return dp[n];
    }
};