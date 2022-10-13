class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[i].size();j++)
                ans[i][j]=sum(mat,i,j,k);
        
        return ans;
    }
    
    int sum(vector<vector<int>> &mat,int i,int j,int k){
        long ans=0;
        int s1=max(0,i-k);
        int s2=max(0,j-k);
        int m=mat.size();
        int n=mat[0].size();
        int e1=min(m-1,i+k);
        int e2=min(n-1,j+k);
        
        for(int p=s1;p<=e1;p++)
            for(int q=s2;q<=e2;q++)
                ans+=mat[p][q];
        
        return ans;
    }
};