class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int targetNumber = 0;
        for(int i=0; i<nums.size(); i++) {
            targetNumber = target - nums[i];
            if(mp.find(targetNumber) != mp.end())
                return {mp[targetNumber] + 1, i + 1};
            
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};