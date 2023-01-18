class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = 0, size = nums.size(), curSum = 0, maxE = -30001;
        vector<int> dp(size, -30001);
        for(int i = 0, sum = 0; i < size; ++i) {
            dp[i] = i == 0 ? sum += nums[i] : max(dp[i-1], sum += nums[i]);
            maxE = max(maxE, nums[i]);
            curSum = max(curSum+nums[i], 0);
            maxSum = max(maxSum, curSum);
        }
        if(maxE < 0) return maxE;
        
        for(int i = size-1, sum = 0; i >= 1; --i)
            maxSum = max(maxSum, dp[i-1] + (sum += nums[i]));
			
        return maxSum;
    }
};