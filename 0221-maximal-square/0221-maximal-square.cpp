class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        return maxSq(matrix);
    }
    int maxSq(vector<vector<char>> &mat){
        if(mat.empty())
            return 0;
        vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),-1));
        
        
        int res=0;
        for(int i=0;i<mat.size();++i)
            for(int j=0;j<mat[0].size();++j)
                res=max(res,helper(mat,i,j,dp));
        
        return res*res;
    }
    int helper(vector<vector<char>>& matrix, int i, int j,vector<vector<int>> &dp) {
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;
        if(dp[i][j]>=0)
            return dp[i][j];
        if (matrix[i][j] == '0')
            return dp[i][j]=0;
        
        return dp[i][j]=min(min(helper(matrix, i, j+1,dp), helper(matrix, i+1, j,dp)), helper(matrix, i+1, j+1,dp)) + 1;
    }
};