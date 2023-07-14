class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string rs=s;
        reverse(rs.begin(),rs.end());
        // cout<<rs;
        int n=s.size();
        vector<int> prev(n+1,0), cur(n+1,0);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==rs[j-1])
                    cur[j] = 1 + prev[j-1];
                else
                    cur[j] = 0 + max(prev[j],cur[j-1]);
            }
            prev=cur;
        }

        return prev[n];
    }
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};