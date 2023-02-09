class Solution {
public:
    Solution() {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
    long long distinctNames(vector<string>& ideas) {
        unordered_map<string, int> headMask;
        for (auto &idea : ideas) {
            headMask[idea.substr(1)] |= 1 << (idea[0] - 'a');
        }
        array<array<array<int, 2>, 26>, 26> cnt{};
        for (auto &[k, mask] : headMask) {
            // cout << k << ' ' << mask << '\n';
            for (int i = 0; i < 26; ++i) {
                for (int j = i + 1; j < 26; ++j) {
                    if (((mask >> i) & 1) ^ ((mask >> j) & 1)) {
                        // cout << i << ' ' << j << ' ' << ((mask >> i) & 1) << ' ' << ((mask >> j) & 1) << '\n';
                        ++cnt[i][j][(mask >> i) & 1];
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                ans += 2ll * cnt[i][j][0] * cnt[i][j][1];
            }
        }
        return ans;
    }
};