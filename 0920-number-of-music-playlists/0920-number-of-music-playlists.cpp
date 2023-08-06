class Solution {
public:
    #define ll long long
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    
    ll solve(int n, int goal, int k) {
        if (n == 0 && goal == 0)
            return 1;
        if (n == 0 || goal == 0)
            return 0;
        
        if(dp[n][goal]!=-1)
            return dp[n][goal];
        
        ll pick = solve(n - 1, goal - 1, k) * n;
        ll notpick = solve(n, goal - 1, k) * max(n - k, 0);
        
        return dp[n][goal]=(pick + notpick) % MOD;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        dp.resize(n+1,vector<int>(goal+1,-1));
        return solve(n,goal,k);
    }
};