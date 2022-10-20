class Solution {
public:
    int dp[12+1][10000+1];
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int res=findLowestCoins(coins,0,amount);
        return res==INT_MAX-1 ? -1 : res;
    }
    
    int findLowestCoins(vector<int> &coins,int curr,int amount){
        if(curr >=coins.size() or amount<=0)
            return amount==0 ? 0 : INT_MAX-1;
        
        if(dp[curr][amount]!=-1)
            return dp[curr][amount];
        
        int res=-1;
        if(coins[curr]>amount){
            int dontake=0+findLowestCoins(coins,curr+1,amount-0);
            dp[curr][amount]=res=dontake;
        }
        else{
            int take=1+findLowestCoins(coins,curr+0,amount-coins[curr]);
            int dontake=0+findLowestCoins(coins,curr+1,amount-0);
            dp[curr][amount]=res=min(take,dontake);
        }
        return dp[curr][amount]=res;
    }
};