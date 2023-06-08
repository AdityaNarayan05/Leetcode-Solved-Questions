class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            
            if(i>0 and nums[i]==nums[i-1])
                continue;
            
            for(int j=i+1;j<n;j++){
                
                if(j>i+1 and nums[j]==nums[j-1])
                    continue;
                
                int lo=j+1,hi=n-1;
                while(lo<hi){
                    
                    long long sum=nums[i]+nums[j];
                    sum+=nums[lo];
                    sum+=nums[hi];
                    
                    if(sum==target){
                        vector<int> temp={nums[i],nums[j],nums[lo],nums[hi]};
                        ans.push_back(temp);
                        lo++;
                        hi--;
                        
                        while(lo<hi and nums[lo]==nums[lo-1])
                            lo++;
                        while(lo<hi and nums[hi]==nums[hi+1])
                            hi--;
                    }
                    else if(sum<target)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return ans;
    }
};