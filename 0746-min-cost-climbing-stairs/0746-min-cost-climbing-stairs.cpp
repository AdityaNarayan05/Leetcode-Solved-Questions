class Solution {
public:
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n,0);
        return min(minCost(cost,n-1),minCost(cost,n-2));
    }
    int minCost(vector<int> cost,int n){
        if(n<0)
            return 0;
        if(n==0 || n==1)
            return cost[n];
        if(dp[n]!=0)
            return dp[n];
        return dp[n]=cost[n]+min(minCost(cost,n-1),minCost(cost,n-2));
    }
};