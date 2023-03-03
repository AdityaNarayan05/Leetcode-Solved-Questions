class Solution {
public:
    // vector<int> dp;
    // dp[0]=0;
    // dp[1]=1;
    int fib(int n) {
        // dp.resize(n,-1);
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        return fib(n-1)+fib(n-2);
        // if(dp[n]!=-1)
        //     return dp[n];
        // for(int i=2;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        // return dp[n]=fib(n-1)+fib(n-2);
    }
};