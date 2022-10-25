class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1,cnt=count(nums.begin(),nums.end(),0);
        if(cnt>1)
            return vector<int> (nums.size());
        for(auto &num:nums)
            if(num)
                prod*=num;
        for(auto &num:nums){
            if(cnt)
                num=num?0:prod;
            else
                num=prod/num;
        }
        return nums;
    }
};