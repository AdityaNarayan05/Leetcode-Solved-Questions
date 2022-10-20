class Solution {
public:
    int dp[58+1][57+1];
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return Break(n,n-1);
    }
    int Break(int n,int curr){
        if(n==0 or curr==0)
            return 1;
        if(dp[n][curr]!=-1)
            return dp[n][curr];
        if(curr>n)
            return dp[n][curr]=Break(n-0,curr-1);
        else
            return dp[n][curr]=max(Break(n-0,curr-1),curr*Break(n-curr,curr));
    }
};