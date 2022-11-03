class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int i, j, ans = 0;
        vector<vector<int>> mp(26, vector<int>(26, 0));
        bool singleSame = false;
        for (auto &w : words)
            mp[w[0] - 'a'][w[1] - 'a']++;
    
        for (i = 0; i < 26; i++) {
            ans += 2 * mp[i][i];
            if (mp[i][i] % 2 == 1){
                ans -= 2;
                singleSame = true;
            }
      
            for (j = i + 1; j < 26; j++) {
                ans += 4 * (min(mp[i][j], mp[j][i]));
            }
        }
        
        if (singleSame)
            ans += 2;
    
        return ans;
    }
};