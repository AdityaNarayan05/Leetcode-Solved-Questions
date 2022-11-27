class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        unordered_map<long, int> mp[max(1, n)];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j) {
                auto it = mp[j].find((long)nums[i] - nums[j]);
                int cnt = it == end(mp[j]) ? 0 : it->second;
            mp[i][((long)nums[i] - nums[j])] += cnt + 1;
            res += cnt;
        }
    return res;
    }
};