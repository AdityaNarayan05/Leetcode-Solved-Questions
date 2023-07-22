class Solution {
    vector<vector<int>> dirs={{-1,-2},{-2,-1},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
    bool checkValidIndex(int row,int column,int n){
        return row<n && column<n && row>=0 && column >=0;
    }
    
    double dfs(int n,vector<vector<vector<double>>> &dp,int k,int row, int column){
        if(checkValidIndex(row,column,n)){
            if(k==0)
                return dp[row][column][k]=1.0;
            
            if(dp[row][column][k]!=-1)
                return dp[row][column][k];
            
            double probability=0;
            for(auto dir:dirs)
                probability += 1.0/8.0*dfs(n,dp,k-1,row+dir[0],column+dir[1]);
            
            return dp[row][column][k]=probability;
        }
        return 0;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>> (n,vector<double>(k+1,-1.0)));
        return dfs(n,dp,k,row,column);
    }
};