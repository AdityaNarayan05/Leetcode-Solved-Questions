class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target+1);
        dp[0]=1;
        for(int curr=1;curr<=target;curr++)
            for(auto& num : nums)
                if(num<=curr)
                    dp[curr]+=dp[curr-num];
        
        return dp[target];
    }
};