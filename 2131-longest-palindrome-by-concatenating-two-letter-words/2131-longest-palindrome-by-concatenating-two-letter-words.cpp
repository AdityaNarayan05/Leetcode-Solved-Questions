class Solution {
public:
    int longestPalindrome(vector<string>& words) {
         
       int cnt[26][26] = {}; 
        int ans=0;
        for(auto w:words){
            int a=w[0]-'a';
            int b=w[1]-'a';
            if(cnt[b][a]){
                ans+=4;
                cnt[b][a]--;
            }else
                cnt[a][b]++;
        }
        for(int i=0;i<26;i++){
            if(cnt[i][i]){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};