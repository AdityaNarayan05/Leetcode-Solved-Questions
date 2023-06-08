class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);
        int l=0,r=0;
        int n=s.size();
        int len=0;
        
        while(r<n){
            char ch=s[r];
            if(mp[ch]!=-1)
                l=max(mp[ch]+1,l);
            
            mp[ch]=r;
            len=max(len,r-l+1);
            r++;
        }
        return len;
    }
};