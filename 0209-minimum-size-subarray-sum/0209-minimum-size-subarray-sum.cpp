class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),minL=INT_MAX,sum=0,l=0,r=0;
        while(r<n){
            sum+=nums[r];
            ++r;
            while(sum>=target){
                minL=min(minL,r-l);
                sum-=nums[l];
                ++l;
            }
        }
        return minL==INT_MAX?0:minL;
    }
};