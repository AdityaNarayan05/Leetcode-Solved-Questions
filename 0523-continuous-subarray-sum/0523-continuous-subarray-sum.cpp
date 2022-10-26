class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp = {{0, -1}};
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cur =  k ? (cur + nums[i]) % k : cur + nums[i];
            mp.insert({cur, i});
            if (i - mp[cur] > 1)
                return true;
        }
        return false;
    }
};