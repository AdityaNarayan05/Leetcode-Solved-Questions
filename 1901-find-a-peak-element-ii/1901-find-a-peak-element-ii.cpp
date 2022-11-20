class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int i=0,j=m-1,up,down,left,right;
        while(1){
            up=i-1<0?-1:mat[i-1][j];
            down=i+1>=n?-1:mat[i+1][j];
            left=j-1<0?-1:mat[i][j-1];
            right=j+1>=m?-1:mat[i][j+1];
            
            if(mat[i][j]>up && mat[i][j]>down && mat[i][j]>left && mat[i][j]>right)
                return {i,j};
            
            int maxi=max({up,down,left,right});
            
            if(up==maxi)
                i--;
            else if
                (down==maxi)i++;
            else if
                (left==maxi)j--;
            else if
                (right==maxi)j++;
        }
        return {-1,-1};
    }
};