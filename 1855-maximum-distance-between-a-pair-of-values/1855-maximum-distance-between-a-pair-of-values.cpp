class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, i = 0, n = nums1.size(), m = nums2.size();
        for (int j = 0; j < m; ++j) {
            while (i < n && nums1[i] > nums2[j])
                i++;
            if (i == n) break;
            res = max(res, j - i);
        }
        return res;
    }
};