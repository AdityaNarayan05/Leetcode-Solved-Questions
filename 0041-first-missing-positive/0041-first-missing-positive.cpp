class Solution {
public:
    int firstMissingPositive(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int ans=1;
        for(auto num:nums){
            if(num==ans){
                ans++;
            }
        }
        return ans;
    }
};