class Solution {
public:
    int dp[1000][1000];
    int longPalinSubseq(string &s,int i,int j){
        if(i==j)
            return 1;
        if(i>j)
            return 0;
        
        if(dp[i][j])
            return dp[i][j];
        
        if(s[i]==s[j])
            return dp[i][j]=2+longPalinSubseq(s,i+1,j-1);
        
        return dp[i][j]=max(longPalinSubseq(s,i+1,j),longPalinSubseq(s,i,j-1));
    }
    int minInsertions(string s) {
        return s.size()-longPalinSubseq(s,0,s.size()-1);
    }
};