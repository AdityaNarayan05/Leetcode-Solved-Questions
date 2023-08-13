class Solution {
public:
    vector<int> dp;
    bool funct(vector<int>& nums, int i){
        if(i == nums.size()) 
            return true;
        if(dp[i] != -1) 
            return dp[i];
        
        if(i + 1 < nums.size() && nums[i] == nums[i+1] ) {
            if(funct(nums, i + 2))
                return true;
            
            if(i + 2 < nums.size() && nums[i] == nums[i+2]){
                if(funct(nums, i + 3))
                    return true;
            }
        }
        
        if(i + 2 < nums.size() && nums[i] == nums[i+1]-1 && nums[i] == nums[i+2] - 2){
            if(funct(nums, i + 3))
                return true;
        }
        return dp[i]=false;
    }
    bool validPartition(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return funct(nums, 0);
    }
};
