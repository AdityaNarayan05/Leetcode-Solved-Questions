class Solution {
public:
    vector<vector<int>> dp;
    int mUl(int i,int j,vector<int>& n1,vector<int>& n2){
        if(i==n1.size() or j==n2.size())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int cnt=0;
        if(n1[i]==n2[j])
            cnt=1+mUl(i+1,j+1,n1,n2);
        else
            cnt+=max(mUl(i+1,j,n1,n2),mUl(i,j+1,n1,n2));
        return dp[i][j]=cnt;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(),vector<int>(nums2.size(), -1));
        return mUl(0,0,nums1,nums2);
    }
};