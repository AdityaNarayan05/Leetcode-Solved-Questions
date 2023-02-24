class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> mp(128,0);
        for(char ch:s)
            mp[ch]++;
        int odd=0;
        for(int m:mp)
            odd+=m&1;
        return s.size()-odd+(odd>0);
    }
};