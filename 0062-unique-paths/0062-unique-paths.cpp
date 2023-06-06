class Solution {
public:
    vector<vector<int>> dp;
    
    int fun(int i,int j){
        if(i==0 && j==0)
            return 1;
        if(i<0 || j<0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = fun(i-1,j)+fun(i,j-1);
    }
    int uniquePaths(int m, int n) {   
        dp.resize(m,vector<int>(n,-1));
        return fun(m-1,n-1);
    }
};