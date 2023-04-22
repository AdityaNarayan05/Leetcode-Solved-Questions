class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        for (int i = n - 1; ~i; --i) {
            int pre = 0;
            for (int j = i + 1; j < n; ++j) {
                int temp = dp[j];
                if (s[i] == s[j]) 
                    dp[j] = pre;
                else dp[j] = 1 + min(dp[j], dp[j - 1]);
                pre = temp;
            }
        }
        return dp[n - 1];
    }
};