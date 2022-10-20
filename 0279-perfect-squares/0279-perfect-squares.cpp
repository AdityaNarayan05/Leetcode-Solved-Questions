class Solution {
public:
    vector<int> dp;
    int numSquares(int n) {
        dp.resize(n+1,-1);
        return numSq(n);
    }
    int numSq(int n){
        if(n==0)
            return 0;
        if(n<0)
            return INT_MAX-1;
        if(dp[n]!=-1)
            return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++)
            ans=min(ans,1+numSq(n-i*i));
        
        return dp[n]=ans;
    }
};