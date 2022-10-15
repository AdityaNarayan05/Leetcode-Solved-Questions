class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return getMinPath(grid,0,0,dp);
    }
    
    int getMinPath(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &dp){
        if(i==grid.size()-1 and j==grid[0].size()-1)
            return grid[i][j];
        if(j==grid[0].size()-1)
            return grid[i][j]+getMinPath(grid,i+1,j,dp);
        if(i==grid.size()-1)
            return grid[i][j]+getMinPath(grid,i,j+1,dp);
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=grid[i][j]+min(getMinPath(grid,i+1,j,dp),getMinPath(grid,i,j+1,dp));
    }
};