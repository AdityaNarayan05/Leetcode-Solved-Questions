const int INF = 1e9;
class Solution {
    vector<vector<int>> memo;
    
    int getLengthOfOptimalCompression(int i, int K, const string& s) {
        const int n = s.length();
        if(i + K >= n) return 0;
        int& ans = memo[i][K];
        if(ans != INF) return ans;
        if(K) ans = getLengthOfOptimalCompression(i+1, K-1, s);
        int counter{1}, k{K};
        for(int j = i+1; j <= n; ++j) {
            ans = min(ans, getLengthOfOptimalCompression(j, k, s) + 1 + (counter >= 100 ? 3 : counter >= 10 ? 2 : counter >= 2 ? 1 : 0));
            if(j == n) break;
            if(s[i] == s[j]) counter++;
            else if(--k < 0) break;
        }
        return ans;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        const int n = s.length();
        memo.assign(n, vector<int>(k+1, INF));
        return getLengthOfOptimalCompression(0, k, s);
    }
};