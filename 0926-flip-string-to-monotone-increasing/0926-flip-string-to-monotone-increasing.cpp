class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> ones(n);
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                ones[i] = (i == 0 ? 0 : ones[i - 1]) + 1;
            } else {
                ones[i] = (i == 0 ? 0 : ones[i - 1]);
            }
        }    
        int min_flips = INT_MAX;
        for(int i = 0; i <= n; i++) {
            int curr_flips = (i == 0 ? 0 : ones[i - 1]);
            curr_flips += (n - i) - (ones[n - 1] - (i == 0 ? 0 : ones[i - 1]));
            
            min_flips = min(min_flips, curr_flips);
        }
        return min_flips;
    }
};