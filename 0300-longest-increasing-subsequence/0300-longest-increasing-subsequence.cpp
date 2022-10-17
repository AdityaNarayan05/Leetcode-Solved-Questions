class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=0;
        for(auto num:nums){
            if(len==0 || nums[len-1]<num)
                nums[len++]=num;
            else
                *lower_bound(nums.begin(),nums.begin()+len,num)=num;
        }
        return len;
    }
};