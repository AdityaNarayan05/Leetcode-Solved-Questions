class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> times(n);
        for (int i = 0; i < n; i++) {
            times[i].first = -growTime[i];
            times[i].second = plantTime[i];
        }
        sort(times.begin(), times.end());
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, cur + times[i].second - times[i].first);
            cur += times[i].second;
        }
        return ans;
    }
};