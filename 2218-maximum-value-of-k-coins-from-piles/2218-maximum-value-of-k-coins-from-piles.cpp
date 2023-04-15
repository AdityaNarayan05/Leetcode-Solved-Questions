class Solution {
public:
    vector<vector<int>> dp;
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        return solve(0,piles,k);
    }
    int solve(int idx,vector<vector<int>> &piles,int k){
        if(idx>=piles.size())
            return 0;
        if(dp[idx][k]!=-1)
            return dp[idx][k];
        
        int maxi=0,sum=0;
        
        maxi=max(maxi,solve(idx+1,piles,k));
        for(int i=0;i<piles[idx].size();i++){
            sum+=piles[idx][i];
            if(k-(i+1)>=0)
                maxi=max(maxi,sum+solve(idx+1,piles,k-(i+1)));
        }
        return dp[idx][k]=maxi;
    }
};