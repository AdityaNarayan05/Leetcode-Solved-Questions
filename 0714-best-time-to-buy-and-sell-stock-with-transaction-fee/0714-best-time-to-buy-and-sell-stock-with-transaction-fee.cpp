class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(n,0); //maximum profit
        int max_prof = dp[0] - prices[0] - fee;
        
        for(int i = 1; i<n; i++){
            dp[i] = max(dp[i-1], max_prof + prices[i]); //do nothing or sell
            
            max_prof = max(max_prof, dp[i] - prices[i] - fee);
        } 
    
        return dp[n-1];
    }
};