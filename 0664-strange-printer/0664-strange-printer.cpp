class Solution {
public:
    vector<vector<int>> dp;
    int funct(int i, int j, string& s){       
        if (i==j) 
            return dp[i][j]=1;
        
        if (dp[i][j]!=-1) 
            return dp[i][j];
        
        int ans; 
        if (s[i]==s[j] or s[j-1]==s[j]) 
            ans=funct(i, j-1, s);
        else if (s[i]==s[i+1]) 
            ans=funct(i+1, j, s);
        else{
            ans=funct(i,j-1, s)+1;
            
            for(int k=i+1; k<j; k++)
                if(s[k]==s[j])
                    ans=min(ans, funct(i, k-1, s)+funct(k, j-1, s));
        }
        return dp[i][j]=ans;
    }
    
    int strangePrinter(string s) {
        int n=s.size();
        dp.resize(n,vector<int>(n,-1));
        return funct(0, n-1, s); 
    }
};