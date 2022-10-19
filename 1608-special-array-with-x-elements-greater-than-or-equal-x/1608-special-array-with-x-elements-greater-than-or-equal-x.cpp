class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // O(NlogN)
        int l = 1, r = nums.size();
        while (l <= r) {
            int m = l + (r - l) / 2;
            auto itr = lower_bound(nums.begin(), nums.end(), m); // O(logN)
            int c = distance(itr, nums.end()); // O(1)
            if (c == m)
                return m;
            else if (c > m)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};