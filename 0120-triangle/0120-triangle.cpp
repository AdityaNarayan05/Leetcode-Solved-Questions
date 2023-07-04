class Solution {
public:
    vector<vector<int>> dp;
    int funct(int i,int j,vector<vector<int>> &grid){
        if(i==grid.size()-1)
            return grid[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int down=grid[i][j]+funct(i+1,j,grid);
        int diagonal=grid[i][j]+funct(i+1,j+1,grid);
        
        return dp[i][j]=min(down,diagonal);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        dp.resize(n,vector<int>(n,-1));
        return funct(0,0,triangle);
    }
};