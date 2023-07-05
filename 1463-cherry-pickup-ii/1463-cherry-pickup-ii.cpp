class Solution {
public:
    vector<vector<vector<int>>> dp;
    int funct(int i,int j1,int j2,vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        
        if(j1<0 or j1>=m or j2<0 or j2>=m)
            return -1e9;
        
        if(i==n-1){
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];
        }
        
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        
        int ans=INT_MIN;
        for(int di=-1;di<=1;di++){
            for(int dj=-1;dj<=1;dj++){
                int sum=0;
                if(j1==j2)
                    sum+=grid[i][j1]+funct(i+1,j1+di,j2+dj,grid);
                else
                    sum+=grid[i][j1]+grid[i][j2]+funct(i+1,j1+di,j2+dj,grid);
                
                ans=max(sum,ans);
            }
        }
        return dp[i][j1][j2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        return funct(0,0,m-1,grid);
    }
};