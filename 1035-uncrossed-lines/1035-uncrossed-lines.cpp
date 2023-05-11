class Solution {
public:
    vector<vector<int>> dp;
//     int mUl(int i,int j,vector<int>& n1,vector<int>& n2){
//         if(i==n1.size() or j==n2.size())
//             return 0;
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         int cnt=0;
//         if(n1[i]==n2[j])
//             cnt=1+mUl(i+1,j+1,n1,n2);
//         else
//             cnt+=max(mUl(i+1,j,n1,n2),mUl(i,j+1,n1,n2));
//         return dp[i][j]=cnt;
//     }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        // dp.resize(nums1.size(),vector<int>(nums2.size(), -1));
        // return mUl(0,0,nums1,nums2);
         dp.resize(n+1,vector<int>(m+1, 0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1] ==nums2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};