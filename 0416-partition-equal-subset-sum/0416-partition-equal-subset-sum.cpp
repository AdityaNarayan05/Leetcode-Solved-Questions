class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);//accumaulate add number of array;
        // cout<<sum<<endl;
        if(sum&1)
            return false;
        sum>>=1;//sum=sum>>1    or sum=sum/2;
        vector<unordered_map<int,bool>> dp(nums.size());
        return dfs(nums,sum,0,dp);
    }
    bool dfs(vector<int>&nums,int sum,int p,vector<unordered_map<int,bool>> &dp){
        if(!sum)
            return true;
        if(sum<0 or p==nums.size())
            return false;
        auto it=dp[p].find(sum);
        if(it!=dp[p].end())
            return it->second;
        return dp[p][sum]=dfs(nums,sum,p+1,dp) or dfs(nums,sum-nums[p],p+1,dp);
    }
};