class Solution {
public:
    vector<int> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size()+1,-1);
        return solve(nums, 0, -1);
    }
    int solve(vector<int>& nums, int i, int prev) {
        if(i >= size(nums))
            return 0;
        
        if(dp[prev+1] != -1)
            return dp[prev+1];
        
        int take = 0, dontTake = solve(nums, i + 1, prev);
        if(prev == -1 || nums[i] > nums[prev])
            take = 1 + solve(nums, i + 1, i);
        
        return dp[prev+1] = max(take, dontTake);
    }
};