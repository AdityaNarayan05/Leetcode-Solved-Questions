class Solution {
public:
    int helper(vector<int>& nums, int l, int r, int minimum){
        int ret = 0;
        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum <= minimum)
                l++;
            else{
                ret += (r - l);
                r--;
            }
        }
        return ret;
    }

    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ret = 0;
        for(size_t i = n-1; i >= 2; --i)
            ret += helper(nums, 0, i-1, nums[i]);
        return ret;
    }
};