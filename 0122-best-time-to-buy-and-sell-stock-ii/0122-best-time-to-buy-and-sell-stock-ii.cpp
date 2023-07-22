class Solution {
public:
    vector<vector<int>> dp;
    int funct(int idx,int buy,vector<int>& nums){
        if(idx==nums.size())
            return 0;
        
        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        
        int op1,op2;
        if(buy==0){
            op1=0+funct(idx+1,0,nums);
            op2=-nums[idx]+funct(idx+1,1,nums);
        }
        if(buy==1){
            op1=0+funct(idx+1,1,nums);
            op2=nums[idx]+funct(idx+1,0,nums);
        }
        
        return dp[idx][buy]=max(op1,op2);
    }
    
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return funct(0,0,prices);
    }
};