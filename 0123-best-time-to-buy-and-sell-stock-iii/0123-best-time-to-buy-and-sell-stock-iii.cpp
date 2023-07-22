class Solution {
public:
    vector<int> nums;
    vector<vector<vector<int>>> dp;
    int funct(int idx,int buy,int cap){
        if(idx==nums.size() or cap==0)
            return 0;
        
        if(dp[idx][buy][cap]!=-1)
            return dp[idx][buy][cap];
        
        int op1,op2;
        if(buy==0){
            op1=0+funct(idx+1,0,cap);
            op2=-nums[idx]+funct(idx+1,1,cap);
        }
        if(buy==1){
            op1=0+funct(idx+1,1,cap);
            op2=nums[idx]+funct(idx+1,0,cap-1);
        }
        
        return dp[idx][buy][cap]=max(op1,op2);
    }
    int maxProfit(vector<int>& prices) {
        nums=prices;
        dp.resize(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return funct(0,0,2);
    }
};