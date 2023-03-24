class Solution {
public:
    vector<int> dp;
    
    int rob(vector<int>& nums){
        dp.resize(nums.size()+1,-1);
        return robRec(nums,0);
    }
    
    int robRec(vector<int> &nums,int idx){
        if(idx>=nums.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        return dp[idx]=max(nums[idx]+robRec(nums,idx+2),robRec(nums,idx+1));
    }
};