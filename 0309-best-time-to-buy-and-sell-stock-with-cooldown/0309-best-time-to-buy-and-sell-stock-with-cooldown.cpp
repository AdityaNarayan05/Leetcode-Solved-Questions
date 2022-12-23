class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(3,vector<int>(2,0));
        for(int day=prices.size()+1;day>=0;day--){
            for(int buy=0;buy<=1;buy++){
                int &ans=dp[day%3][buy];
                
                if(day>=prices.size())
                    ans=0;
                else{
                    int ans1=dp[(day+1)%3][buy];
                    
                    int ans2=0;
                    if(buy)
                        ans2=-prices[day]+dp[(day+1)%3][0];
                    else
                        ans2=prices[day]+dp[(day+2)%3][1];
                    
                    ans=max(ans1,ans2);
                }
            }
        }
        return dp[0][1];
    }
};