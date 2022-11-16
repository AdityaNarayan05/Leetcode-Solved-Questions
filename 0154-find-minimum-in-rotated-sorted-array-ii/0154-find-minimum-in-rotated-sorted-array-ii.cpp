class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums[0];
        return n;
    }
};