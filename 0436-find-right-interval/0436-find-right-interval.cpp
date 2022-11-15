class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> ans(n);
        map<int, int> m;
        for(int i = 0; i < n; i++)
            m[intervals[i][0]] = i;
        for(int i = 0; i < n; i++) 
               ans[i] = m.lower_bound(intervals[i][1])!=end(m) ? m.lower_bound(intervals[i][1]) -> second : -1;
        return ans;
    }
};