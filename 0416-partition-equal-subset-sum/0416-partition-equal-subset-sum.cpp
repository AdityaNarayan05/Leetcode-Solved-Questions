class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum&1) 
            return 0;
        vector<bool> dp(1+(sum>>=1));
        dp[0]=1;
        for(int n:nums) {
            for(int i=sum-1;i>=0;i--) {
                if(!dp[i]) continue;
                if(i+n<=sum) dp[i+n]=1;
            }
            if(dp[sum]) return 1;
        }
        return 0;
    }
};