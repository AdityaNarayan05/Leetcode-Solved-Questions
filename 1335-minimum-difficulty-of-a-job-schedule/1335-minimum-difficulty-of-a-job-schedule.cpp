class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n)
            return -1;
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        return mDiff(jobDifficulty,0,n,d,dp);
    }
    
    int mDiff(vector<int> &jD,int start,int n,int d,vector<vector<int>> &dp){
        if(d==1){
            int maxi=jD[start];
            for(int i=start+1;i<n;i++)
                maxi=max(maxi,jD[i]);
            
            return maxi;
        }
        if(dp[start][d]!=-1)
            return dp[start][d];
        
        int maxi=INT_MIN;
        int res=INT_MAX;
        
        for(int i=start;i<n-d+1;i++){
            maxi=max(maxi,jD[i]);
            res=min(res,maxi+mDiff(jD,i+1,n,d-1,dp));
        }
        return dp[start][d]=res;
    }
};