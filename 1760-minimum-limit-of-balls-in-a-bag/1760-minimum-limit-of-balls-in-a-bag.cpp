class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = (l + r) / 2, cnt = 0;
            for (int num : nums)
                cnt += (num - 1) / mid;
            if (cnt > maxOperations)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};