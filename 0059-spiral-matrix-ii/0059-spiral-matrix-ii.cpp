class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int i=0,j;
        for(int k=1;k<=n*n;i++){
            
            for(j=i;j<n-i;j++)
                res[i][j]=k++;
            
            for(j=i+1;j<n-i;j++)
                res[j][n-i-1]=k++;
            
            for(j=n-i-2;j>i;j--)
                res[n-i-1][j]=k++;
            
            for(j=n-i-1;j>i;j--)
                res[j][i]=k++;
        }
        return res;
    }
};