class Solution {
public:
    // int numberOfArithmeticSlices(vector<int>& nums) {
    //     int res=0;
    //     int n=nums.size();
    //     unordered_map<long, int> mp[max(1, n)];
    //     for (int i = 0; i < n; ++i)
    //         for (int j = 0; j < i; ++j) {
    //             auto it = mp[j].find((long)nums[i] - nums[j]);
    //             int cnt = it == end(mp[j]) ? 0 : it->second;
    //         mp[i][((long)nums[i] - nums[j])] += cnt + 1;
    //         res += cnt;
    //     }
    // return res;
    // }
    
    // dp approach
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        // dp[i][j] := # of subseqs end w/ nums[j] nums[i]
        vector<vector<int>> dp(n, vector<int>(n));
        unordered_map<long, vector<int>> mp;

        for (int i = 0; i < n; ++i)
            mp[nums[i]].push_back(i);
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j) {
                const long target = nums[j] * 2L - nums[i];
                if (mp.count(target))
                    for (const int k : mp[target])
                        if (k < j)
                            dp[i][j] += (dp[j][k] + 1);
                ans += dp[i][j];
            }
        return ans;
    }
};