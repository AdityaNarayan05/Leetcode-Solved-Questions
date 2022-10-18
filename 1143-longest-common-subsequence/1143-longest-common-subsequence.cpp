class Solution {
public:
    #define vi vector<int>
    #define vvi vector<vi>
    #define rep(i,a,b) for(int i=a;i<b;i++)
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
    int m=s2.size();
        vvi d(n+1,vi(m+1,-1));
    rep(i,0,n+1){
        rep(j,0,m+1){
            if(i==0 or j==0){
                d[i][j]=0;
                continue;
            }
            if(s1[i-1]==s2[j-1]){
                d[i][j]=1+d[i-1][j-1];
            }
            else{
                d[i][j]=max(d[i][j-1],d[i-1][j]);
            }
        }
    }
    return d[n][m];
    }
};