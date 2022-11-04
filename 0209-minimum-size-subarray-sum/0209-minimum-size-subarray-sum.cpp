class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),minL=n+1,l=0;
        for(int r=0;r<n;++r){
            target-=nums[r];
            while(target<=0){
                minL=min(minL,r-l+1);
                target+=nums[l];
                ++l;
            }
        }
        return minL%(n+1);
    }
};