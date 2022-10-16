class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n)
            return -1;
        vector<vector<int>> dp(n+1,vector<int>(d+1,1e9));
        dp[0][0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= d; j++){
                int maxi = INT_MIN;
                for(int k = i - 1; k >= j - 1; k--){
                    maxi = max(maxi, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], maxi + dp[k][j - 1]);
                }
            }
        }

        return dp[n][d];
    }
};