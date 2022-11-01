class Solution {
public:
    int dp[102][102];
    int n,m;
    bool isValid(int x,int y){
         return (x>=0 and x<n and y>=0 and y<m);
    }
    int findB(vector<vector<int>> &grid,int r,int c){
        if(r==n)//exit condition
            return c;
        
        if(isValid(r,c)){
            if(grid[r][c]==1 and isValid(r,c+1) and grid[r][c+1]==1){
                if(dp[r+1][c+1]!=-2)
                    return dp[r+1][c+1];
                else
                    return dp[r+1][c+1]=findB(grid,r+1,c+1);
            }
            else if(grid[r][c]==-1 and isValid(r,c-1) and grid[r][c-1]==-1){
                if(dp[r+1][c-1]!=-2)
                    return dp[r+1][c-1];
                else
                    return dp[r+1][c-1]=findB(grid,r+1,c-1);
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<=101;i++)
            for(int j=0;j<=101;j++)
                dp[i][j]=-2;
        
        vector<int> ans(m);
        for(int i=0;i<m;i++)
            ans[i]=findB(grid,0,i);
        
        return ans;
    }
};